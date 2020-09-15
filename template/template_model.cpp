#include <Rcpp.h>
using namespace Rcpp;

#include "model.h"


///////////////////////////////////////////
// Evaluate log prior.                   //
///////////////////////////////////////////

// // [[Rcpp::export]]
// double evaluate_log_prior(const NumericVector &inputs)
// {
//   double output;
//   return output;
// }
//
// // [[Rcpp::export]]
// XPtr<EvaluateLogDistributionPtr> store_evaluate_log_prior()
// {
//   return(XPtr<EvaluateLogDistributionPtr>(new EvaluateLogDistributionPtr(&evaluate_log_prior)));
// }



///////////////////////////////////////////
// Simulate from prior.                  //
///////////////////////////////////////////

// // [[Rcpp::export]]
// NumericVector simulate_prior()
// {
//   NumericVector output;
//   return output;
// }
//
// // [[Rcpp::export]]
// XPtr<SimulateDistributionPtr> store_simulate_prior()
// {
//   return(XPtr<SimulateDistributionPtr>(new SimulateDistributionPtr(&simulate_prior)));
// }



///////////////////////////////////////////
// Evaluate log likelihood.              //
///////////////////////////////////////////

// // [[Rcpp::export]]
// double evaluate_log_likelihood(const NumericVector &inputs, const NumericMatrix &data)
// {
//   double output;
//   return output;
// }
//
// // [[Rcpp::export]]
// XPtr<EvaluateLogLikelihoodPtr> store_evaluate_log_likelihood()
// {
//   return(XPtr<EvaluateLogLikelihoodPtr>(new EvaluateLogLikelihoodPtr(&evaluate_log_likelihood)));
// }



///////////////////////////////////////////
// Simulate from model.                  //
///////////////////////////////////////////

// // [[Rcpp::export]]
// List simulate_model(const NumericVector &inputs, const NumericMatrix &data)
// {
//   List output;
//   return output;
// }
//
// // [[Rcpp::export]]
// XPtr<SimulateModelPtr> store_simulate_model()
// {
//   return(XPtr<SimulateModelPtr>(new SimulateModelPtr(&simulate_model)));
// }




















// // [[Rcpp::export]]
// XPtr<SimulateDistributionPtr> store_simulate_importance_proposal()
// {
//   return(XPtr<SimulateDistributionPtr>(new SimulateDistributionPtr(&simulate_importance_proposal)));
// }
