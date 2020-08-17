evaluate_log_prior = function(inputs)
{
  dgamma(inputs,1,1,log=TRUE)
}

simulate_prior = function()
{
  rgamma(1,1,1)
}

evaluate_log_likelihood = function(inputs,data)
{
  sum(dnorm(data,mean=0,sd=inputs,log=TRUE))
}

simulate_model = function(inputs,data)
{
  rnorm(length(data),mean=0,sd=inputs)
}
