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


/***sbi_likelihood,ilike::abc_l2_uniform(y,1,epsilon,25,false)***/

/***sbi_likelihood,ilike::sl(y,10,unbiased,parallel)***/

/***likelihood,iilike::is(is.cpp,100,FALSE)***/

/***likelihood,iilike::smc_mcmc_move(smc.cpp,100,FALSE)***/

/***likelihood,iilike::marginal_smc(smc.cpp,100,FALSE)***/

/***likelihood,iilike::generic_smc(smc.cpp,100,FALSE)***/

/***likelihood,iilike::pf(smc.cpp,100,FALSE)***/

/***likelihood,iilike::kf(kf.cpp,100,FALSE)***/

/***likelihood,iilike::enk_inversion(kf.cpp,100,FALSE)***/

/***likelihood,iilike::enkf(kf.cpp,100,FALSE)***/

/***adaptive_resampling,ilike::ess(0.5)***/

/***adaptive_target,ilike::cess(0.9)***/

/***smc_termination,ilike::stable(0.1,5)***/

/***smc_sequence,ilike::annealing(power,c(0,1))***/
