/***data***/
Data data()
{
  Data data;
  return data;
}

/***evaluate_log_prior***/
double evaluate_log_prior(const Parameters &parameters)
{
  return log(0.5*exp(dnorm(parameters["x"][0], -7.0, 1.0)) + 0.5*exp(dnorm(parameters["x"][0], 7.0, 1.0)));
}

/***evaluate_log_importance_proposal***/
double evaluate_log_importance_proposal(const Parameters &parameters)
{
  return dnorm(parameters["x"][0], 0.0, 10.0);
}

/***simulate_importance_proposal***/
Parameters simulate_importance_proposal(RandomNumberGenerator &rng)
{
  Parameters output;
  output["x"] = rnorm(rng, 0.0, 10.0);
  return output;
}

/***simulate_m_proposal***/
Parameters simulate_mh_proposal(RandomNumberGenerator &rng,
                                const Parameters &parameters)
{
  Parameters output;
  output["x"] = rnorm(rng,parameters["x"][0],1.0);
  return output;
}

/***mcmc_weights,c(1)***/

/***mcmc_termination,ilike::iterations(1)***/

/***smc_sequence,ilike::annealing(power,c(0,1))***/

/***adaptive_target,ilike::cess(0.96)***/
