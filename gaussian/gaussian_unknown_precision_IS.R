library(ilike)
library(tictoc)

###################
# Using R model.  #
###################

data(gaussian)

number_of_points = 10000

source("gaussian_unknown_precision_model.R")

model = list(simulate_prior = simulate_prior,
             evaluate_log_likelihood = evaluate_log_likelihood,
             data = gaussian)

output_r = importance_sample(number_of_points,
                             model)


###################
# Using C++ model.#
###################

library(Rcpp)
sourceCpp("gaussian_unknown_precision_model.cpp")

model = list(simulate_prior=store_simulate_prior(),
             evaluate_log_likelihood=store_evaluate_log_likelihood(),
             data = gaussian)

output_cpp = importance_sample_cpp(number_of_points,
                                   model)
