// [[Rcpp::plugins("cpp11")]]
// [[Rcpp::depends(ilike, RcppArmadillo, BH, dqrng, sitmo)]]

#include <ilike.h>

/***data***/
Data data()
{
  RandomNumberGenerator rng;
  rng.seed(1);
  size_t n = 100;
  //arma::colvec sampled = rnorm(rng,n);
  arma::colvec sampled(n);
  for (size_t i = 0; i<n; ++i)
    sampled[i] = rnorm(rng,0.0,1.0);
  Data data;
  data["y"] = sampled;
  return data;
}

/***evaluate_log_prior***/
double evaluate_log_prior(const Parameters &inputs)
{
  return dlnorm(inputs["tau"][0], 1.0, 1.0);
}


/***simulate_prior***/
Parameters simulate_prior(RandomNumberGenerator &rng)
{
  Parameters output;
  output["tau"] = rlnorm(rng, 1.0, 1.0);
  return output;
}

/***evaluate_log_likelihood***/
double evaluate_log_likelihood(const Parameters &inputs, const Data &observed_data)
{
  double precision = inputs["tau"][0];
  return sum(dnorm(observed_data["y"], 0.0, 1.0/sqrt(precision)));
}

/***simulate_model***/
Data simulate_model(RandomNumberGenerator &rng,
                    const Parameters &parameters)
{
  Data output;
  size_t n = 100;
  //arma::mat tau = parameters["tau"];
  //std::cout << parameters;
  double precision = parameters["tau"][0];
  output["y"] = rnorm(rng, n, 0.0, 1.0/sqrt(precision));
  return output;
}

/*
Parameters simulate_independent_proposal(RandomNumberGenerator &rng,
                                         const Parameters &proposal_parameters)
{
  Parameters output;
  output["tau"] = rlnorm(rng, 1.0, 1.0);
  return output;
}

double evaluate_log_proposal(const Parameters &inputs)
{
  return dlnorm(inputs["tau"][0], 1.0, 1.0);
}

 double evaluate_log_abc_kernel(const Data &simulated_data, const Data &observed_data)
 {
 return uniform_abc_kernel(simulated_data["y"],observed_data["y"],simulated_data["epsilon"][0]);
 }
 */

/***transform_parameters***/
Parameters transform_parameters(const Parameters &input)
{
  return Parameters("tau",log(input["tau"][0]));
}

/***inverse_transform_parameters***/
Parameters inverse_transform_parameters(const Parameters &input)
{
  return Parameters("tau",exp(input["tau"][0]));
}

/***summary_statistics***/
Data summary_statistics(const Data &data)
{
  return Data("sd",arma::stddev(data["y"]));
}
