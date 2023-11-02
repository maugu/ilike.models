my_rnorm = function(n)
{
  return(rnorm(n))
}

my_dlnorm = function(tau,m,s,l)
{
  return(dlnorm(tau,m,s,l))
}

my_grad_log_prior = function(variable,parameters)
{
  if (variable=="tau")
  {
    stop('Not written yet.')
  }
  else
  {
    stop('Can only take the gradient with respect to "tau".')
  }
}

my_rlnorm = function(n,m,s)
{
  return(rlnorm(n,m,s))
}

my_dnorm = function(y,m,s,l)
{
  return(dnorm(y,m,s,l))
}

my_grad_log_llhd = function(variable,parameters,data)
{
  return(0)
}
