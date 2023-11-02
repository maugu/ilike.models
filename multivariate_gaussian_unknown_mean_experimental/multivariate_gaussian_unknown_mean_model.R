library(mvtnorm)
library(reticulate)

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
