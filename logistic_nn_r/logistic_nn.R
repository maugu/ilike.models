library(mvtnorm)
library(matrixStats)

# Define activation functions, etc.

identity_af = function(x)
{
  return(x)
}

logistic_af = function(x)
{
  return(1/(1+exp(-x)))
}

log_logistic_af = function(x)
{
  return(-log(1+exp(-x)))
}

tanh_af = function(x)
{
  return(2*logistic_af(2*x)-1)
}


# Prepare data.

data(iris)
index_versicolor = which(iris[,5]=='versicolor')
index_virginica = which(iris[,5]=='virginica')
index_setosa = which(iris[,5]=='setosa')
iris[,5] = 1
iris[index_virginica,5] = 2
iris[index_setosa,5] = 3
iris[,5] = factor(iris[,5])
x <- iris[1:150, c("Sepal.Length", "Sepal.Width", "Species")]

index = 1:149
number_train = 149
x_train = as.matrix(x[index[1:number_train],1:2])
y_train = x[index[1:number_train],3]
x_test = as.matrix(x[index[number_train+1],1:2])
y_test = x[index[number_train+1],3]

index_of_class1 = which(y_train==1)
index_of_class2 = which(y_train==2)
index_of_class3 = which(y_train==3)
index_of_each_class_in_y_train = list(index_of_class1,index_of_class2,index_of_class3)


# Define neural network.

num_class = length(unique(y_train))
num_layers = 3
num_in_each_layer = list(5,5,num_class)

activation_functions = list()
activation_functions[[1]] = tanh_af
activation_functions[[2]] = tanh_af
activation_functions[[3]] = identity_af

num_beta = (ncol(x_train)+1)*num_in_each_layer[[1]]
if (length(num_in_each_layer)>1)
{
  for (i in 1:(length(num_in_each_layer)-1))
  {
    num_beta = num_beta + (num_in_each_layer[[i]]+1)*num_in_each_layer[[i+1]]
  }
}

# Define prior parameters.

mu_beta = matrix(0,num_beta)
Sigma_beta = matrix(0,num_beta,num_beta)
for (i in 1:num_beta)
{
  Sigma_beta[i,i] = 100
}


# Functions used in log-likelihood.

log_soft_max = function(log_probs)
{
  sum_probs = rowLogSumExps(log_probs)
  sum_probs_rep = kronecker(matrix(1,1,ncol(log_probs)),sum_probs)
  return(log_probs - sum_probs_rep)
}

log_class_probs_nn = function(x_points,beta,num_classes,num_layers,num_in_each_layer,activation_functions)
{
  activated_variables = x_points
  
  current_beta_position = 0
  
  for (l in 1:num_layers)
  {
    activated_variables = cbind(matrix(1,nrow(activated_variables),1),activated_variables)
    new_activated_variables = matrix(0,nrow(activated_variables),num_in_each_layer[[l]])
    for (m in 1:num_in_each_layer[[l]])
    {
      new_activated_variables[,m] = apply(as.matrix(activated_variables)%*%as.matrix(beta[(current_beta_position+1):(current_beta_position+ncol(activated_variables))]),1,activation_functions[[l]])
      current_beta_position = current_beta_position+ncol(activated_variables)
    }
    activated_variables = new_activated_variables
  }
  
  return(log_soft_max(activated_variables))
}


load_2d_iris = function()
{
  return(list(x=x_train,y=y_train))
}

my_dmvnorm = function(mu,m,s,l)
{
  return(dmvnorm(mu,m,s,l))
}

my_log_prior = function(parameters)
{
  return(dmvnorm(parameters$beta,mu_beta,Sigma_beta,log=TRUE))
}

my_grad_log_prior = function(variable,parameters)
{
  if (variable=="mu")
  {
    stop('Not written yet.')
  }
  else
  {
    stop('Can only take the gradient with respect to "mu".')
  }
}

my_rmvnorm = function(n,m,s)
{
  return(rmvnorm(n,m,s))
}

my_log_llhd = function(parameters,data)
{
  num_classes = length(index_of_each_class_in_y_train)
  
  log_probs_of_class = log_class_probs_nn(data$x,parameters$beta,num_classes,num_layers,num_in_each_layer,activation_functions)
  
  terms_in_product = matrix(0,number_train)
  for (i in 1:num_classes)
  {
    terms_in_product[index_of_each_class_in_y[[i]]] = log_probs_of_class[index_of_each_class_in_y[[i]],i]
  }
  log_llhd = sum(terms_in_product)
  return(log_llhd)
}

my_grad_log_llhd = function(variable,parameters,data)
{
  n = nrow(data$y)
  if (variable=="mu")
  {
    return(solve(Sigma)%*%(-n*as.matrix(parameters$mu) + colSums(as.matrix(data$y))))
  }
  else
  {
    stop('Can only take the gradient with respect to "mu".')
  }
}
