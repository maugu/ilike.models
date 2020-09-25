evaluate_log_prior = function(inputs)
{
  return(dgamma(inputs$precision, 1, 1, log=TRUE))
}

simulate_prior = function()
{
  return(list(precision=rgamma(1, 1, 1)))
}

evaluate_log_likelihood = function(inputs, observed_data)
{
  return(sum(dnorm(observed_data$data, mean=0, sd=1/sqrt(inputs$precision), log=TRUE)))
}

simulate_model = function(inputs, observed_data)
{
  return(list(data = rnorm(length(observed_data$data), mean=0, sd=1/sqrt(inputs$precision))))
}

summary_statistics = function(observed_data)
{
  return(observed_data$data)
}
