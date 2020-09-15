#include <Rcpp.h>
using namespace Rcpp;

#include "model.h"


///////////////////////////////////////////
// Evaluate log prior.                   //
///////////////////////////////////////////

// [[Rcpp::export]]
double evaluate_log_prior(const NumericVector &inputs)
{
  return Rcpp::dgamma(inputs,1,1,TRUE)[0];
}

// [[Rcpp::export]]
XPtr<EvaluateLogDistributionPtr> store_evaluate_log_prior()
{
  return(XPtr<EvaluateLogDistributionPtr>(new EvaluateLogDistributionPtr(&evaluate_log_prior)));
}



///////////////////////////////////////////
// Simulate from prior.                  //
///////////////////////////////////////////

// [[Rcpp::export]]
NumericVector simulate_prior()
{
  return Rcpp::rgamma(1,1,1);
}

// [[Rcpp::export]]
XPtr<SimulateDistributionPtr> store_simulate_prior()
{
  return(XPtr<SimulateDistributionPtr>(new SimulateDistributionPtr(&simulate_prior)));
}



///////////////////////////////////////////
// Evaluate log likelihood.              //
///////////////////////////////////////////

// [[Rcpp::export]]
double evaluate_log_likelihood(const NumericVector &inputs, const NumericMatrix &data)
{
  return sum(Rcpp::dnorm(data(_,0),0,inputs[0],TRUE));
}

// [[Rcpp::export]]
XPtr<EvaluateLogLikelihoodPtr> store_evaluate_log_likelihood()
{
  return(XPtr<EvaluateLogLikelihoodPtr>(new EvaluateLogLikelihoodPtr(&evaluate_log_likelihood)));
}



///////////////////////////////////////////
// Estimate log likelihood.              //
///////////////////////////////////////////

// [[Rcpp::export]]
double estimate_log_likelihood(const NumericVector &inputs, const NumericMatrix &data, const List &aux)
{
  return sum(Rcpp::dnorm(data(_,0),0,inputs[0],TRUE));
}

// [[Rcpp::export]]
XPtr<EstimateLogLikelihoodPtr> store_estimate_log_likelihood()
{
  return(XPtr<EstimateLogLikelihoodPtr>(new EstimateLogLikelihoodPtr(&estimate_log_likelihood)));
}


///////////////////////////////////////////
// Simulate from model.                  //
///////////////////////////////////////////

// [[Rcpp::export]]
List simulate_model(const NumericVector &inputs, const NumericMatrix &data)
{
  NumericMatrix output(data.nrow(), data.ncol());
  output(_,0) = Rcpp::rnorm(data.nrow(),0,inputs[0]);

  //Rcpp::Rcout << "Std: " << inputs[0]  << std::endl;
  //Rcpp::Rcout << "Mean: " << mean(output)  << std::endl;
  //Rcpp::Rcout << "Std: " << sd(output)  << std::endl;
  return List::create(output);
}

// [[Rcpp::export]]
XPtr<SimulateModelPtr> store_simulate_model()
{
  return(XPtr<SimulateModelPtr>(new SimulateModelPtr(&simulate_model)));
}
