my_rnorm = function(n)
{
  return(rnorm(n))
}

my_dlnorm = function(tau,m,s,l)
{
  return(dlnorm(parameters.tau,m,s,l))
}

my_rlnorm = function(n,m,s)
{
  return(rlnorm(n,m,s))
}

my_dnorm = function(y,m,s,l)
{
  return(dnorm(y,m,s,l))
}
