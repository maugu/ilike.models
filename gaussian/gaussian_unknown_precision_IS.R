library(ilike)
library(tictoc)


data(gaussian)

number_of_points = 1000000
number_of_likelihood_particles = 50


###################
# Using R model.  #
###################

source("gaussian_unknown_precision_model.R")

model = list(simulate_prior = simulate_prior,
             evaluate_log_likelihood = evaluate_log_likelihood,
             observed_data = list(data = gaussian))

algorithm = list(number_of_points = number_of_points)

tic()
exact_r_output = importance_sample(model, algorithm)
toc()


model = list(simulate_prior = simulate_prior,
             simulate_model = simulate_model,
             observed_data = list(data = gaussian))

algorithm = list(number_of_points = number_of_points,
                 number_of_likelihood_particles = number_of_likelihood_particles,
                 summary_statistics = summary_statistics)

tic()
#abc_r_output = importance_sample(model, algorithm)
toc()



###################
# Using C++ model.#
###################

library(Rcpp)
sourceCpp("gaussian_unknown_precision_model.cpp")

model = list(simulate_prior = store_simulate_prior(),
             evaluate_log_likelihood = store_evaluate_log_likelihood(),
             observed_data = list(data = gaussian))

algorithm = list(number_of_points = number_of_points)

tic()
exact_cpp_output = importance_sample_cpp(model, algorithm)
toc()


model = list(simulate_prior = store_simulate_prior(),
             simulate_model = store_simulate_model(),
             observed_data = list(data = gaussian))

algorithm = list(number_of_points = number_of_points,
                 number_of_likelihood_particles = number_of_likelihood_particles,
                 summary_statistics = store_summary_statistics())

tic()
#abc_cpp_output = importance_sample_cpp(model,algorithm)
toc()
