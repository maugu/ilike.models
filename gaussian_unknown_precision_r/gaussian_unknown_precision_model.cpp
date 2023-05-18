/***data,y=my_rnorm(100)***/

/***evaluate_log_prior,my_dlnorm(parameters.tau,1,1,TRUE)***/

/***simulate_prior,tau=my_rlnorm(1,1,1)***/

/***evaluate_log_likelihood,sum(my_dnorm(data.y,0,1/sqrt(parameters.tau),TRUE))***/

