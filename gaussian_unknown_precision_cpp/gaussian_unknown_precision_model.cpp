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
