#include "ilike_header.h"

/***data***/
Data data()
{
  RandomNumberGenerator rng;
  rng.seed(1);
  size_t n = 100;

  size_t dimension = 2;
  arma::colvec mu(dimension);
  arma::mat Sigma = arma::eye(dimension,dimension);

  arma::mat sampled = rmvnorm(rng,n,mu,Sigma);
  Data data;
  data["y"] = sampled;
  return data;
}

/***evaluate_log_prior***/
double evaluate_log_prior(const Parameters &parameters)
{
  size_t dimension = 2;
  arma::colvec mu(dimension);
  arma::mat Sigma = 10.0*arma::eye(dimension,dimension);
  return dmvnorm(parameters["mu"], mu, Sigma);
}

/***simulate_prior***/
Parameters simulate_prior(RandomNumberGenerator &rng)
{
  size_t dimension = 2;
  arma::colvec mu(dimension);
  arma::mat Sigma = 10.0*arma::eye(dimension,dimension);
  Parameters p;
  p["mu"] = rmvnorm(rng,1,mu,Sigma);
  return p;
}

/***evaluate_log_likelihood***/
double evaluate_log_likelihood(const Parameters &p,
                               const Data &d)
{
  size_t dimension = 2;
  arma::colvec mu = p["mu"];
  arma::mat Sigma = arma::eye(dimension,dimension);
  Sigma(1,1) = 1000000.0;
  arma::mat y = d["y"];
  size_t n = y.n_cols;
  
  //Rcout << mu << std::endl;
  
  double sum = 0.0;
  for (size_t i=0; i<n; ++i)
  {
    sum = sum + dmvnorm(y.col(i),mu,Sigma);
  }
  
  //Rcout << sum << std::endl;
  
  return sum;
}
