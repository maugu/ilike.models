library(mvtnorm)

d = 2
Sigma = diag(d)
Sigma[2,2] = 1000000

my_dmvnorm = function(mu,m,s,l)
{
  return(dmvnorm(mu,m,s,l))
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
  return(sum(dmvnorm(data$y,parameters$mu,Sigma,TRUE)))
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
