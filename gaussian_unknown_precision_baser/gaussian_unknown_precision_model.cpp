// [[Rcpp::plugins("cpp11")]]
// [[Rcpp::depends(ilike, RcppArmadillo, BH, dqrng, sitmo)]]

#include <ilike.h>

/***data,y=rnorm(100)***/

/***evaluate_log_prior,dlnorm(parameters.tau,1,1,TRUE)***/

/***simulate_prior,tau=rlnorm(1,1,1)***/

/***evaluate_log_likelihood,sum(dnorm(data.y,0,1/sqrt(parameters.tau),TRUE))***/

