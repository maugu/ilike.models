my_data_gen = function()
{
  return(list(y=rnorm(100)))
}

my_rnorm = function(n)
{
  return(rnorm(n))
}

my_dnorm = function(mu,m,s,l)
{
  return(dnorm(mu,m,s,l))
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

my_rnorm = function(n,m,s)
{
  return(rnorm(n,m,s))
}

my_dnorm = function(y,m,s,l)
{
  return(dnorm(y,m,s,l))
}

my_grad_log_llhd = function(variable,parameters,data)
{
  sigma = 1
  n = length(data$y)
  if (variable=="mu")
  {
    return(1/(sigma^2)*(-n*parameters$mu + sum(data$y)))
  }
  else
  {
    stop('Can only take the gradient with respect to "mu".')
  }
}
