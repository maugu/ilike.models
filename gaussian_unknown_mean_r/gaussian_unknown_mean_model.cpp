/***data,my_data_gen()***/

/***evaluate_log_prior,my_dnorm(parameters.mu,0,1,TRUE)***/

/***evaluate_gradient_log_prior,my_grad_log_prior(variable,parameters)***/

/***simulate_prior,mu=my_rnorm(1,0,1)***/

/***evaluate_log_likelihood,sum(my_dnorm(data.y,parameters.mu,1,TRUE))***/

/***evaluate_gradient_log_likelihood,my_grad_log_llhd(variable,parameters,data)***/
