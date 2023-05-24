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

/***prior,ilike::lnorm(tau,1,1)***/

/***evaluate_log_likelihood***/
double evaluate_log_likelihood(const Parameters &parameters, const Data &data)
{
  double precision = parameters["tau"][0];
  return sum(dnorm(data["y"], 0.0, 1.0/sqrt(precision)));
}
