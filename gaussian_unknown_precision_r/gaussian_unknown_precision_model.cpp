#include "gaussian_unknown_precision_model.h"
#include "utils.h"

/***data***/
Data data()
{
  RandomNumberGenerator rng;
  rng.seed(1);
  size_t n = 100;
  arma::colvec sampled = rnorm(rng,n);
  Data data;
  data["y"] = sampled;
  return data;
}

/***evaluate_log_prior***/
double evaluate_log_prior(const Parameters &parameters)
{
  return dlnorm(parameters["tau"][0], 1.0, 1.0);
}

/***simulate_prior***/
Parameters simulate_prior(RandomNumberGenerator &rng)
{
  Parameters output;
  output["tau"] = rlnorm(rng, 1.0, 1.0);
  return output;
}

/***evaluate_log_likelihood***/
double evaluate_log_likelihood(const Parameters &parameters, const Data &data)
{
  double precision = parameters["tau"][0];
  return sum(dnorm(data["y"], 0.0, 1.0/sqrt(precision)));
}

/***simulate_model***/
Data simulate_model(RandomNumberGenerator &rng,
                    const Parameters &parameters)
{
  Data output;
  size_t n = 100;
  double precision = parameters["tau"][0];
  output["y"] = rnorm(rng, n, 0.0, 1.0/sqrt(precision));
  return output;
}

/***simulate_independent_proposal***/
Parameters simulate_independent_proposal(RandomNumberGenerator &rng,
                                         const Parameters &proposal_parameters)
{
  Parameters output;
  output["tau"] = rlnorm(rng, 1.0, 1.0);
  return output;
}

/***evaluate_log_proposal***/
double evaluate_log_proposal(const Parameters &parameters)
{
  return dlnorm(parameters["tau"][0], 1.0, 1.0);
}

/*
double evaluate_log_abc_kernel(const Data &simulated_data, const Data &observed_data)
{
  return uniform_abc_kernel(simulated_data["y"],observed_data["y"],simulated_data["epsilon"][0]);
}
*/

/***transform_parameters***/
Parameters transform_parameters(const Parameters &parameters)
{
  return Parameters("tau",log(parameters["tau"][0]));
}

/***inverse_transform_parameters***/
Parameters inverse_transform_parameters(const Parameters &parameters)
{
  return Parameters("tau",exp(parameters["tau"][0]));
}

/***summary_statistics***/
Data summary_statistics(const Data &data)
{
  return Data("sd",arma::stddev(data["y"]));
}
