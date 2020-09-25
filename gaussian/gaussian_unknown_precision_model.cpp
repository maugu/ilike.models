#include "model.h"


///////////////////////////////////////////
// Evaluate log prior.                   //
///////////////////////////////////////////

// double evaluate_log_prior(const NumericVector &inputs)
// {
//   return Rcpp::dgamma(inputs,1,1,TRUE)[0];
// }

// [[Rcpp::export]]
double evaluate_log_prior(const List &inputs)
{
  double precision = inputs["precision"];
  return R::dgamma(precision, 1.0, 1.0, TRUE);
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
List simulate_prior()
{
  double precision = R::rgamma(1.0, 1.0);
  return List::create(Named("precision") = precision);
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
double evaluate_log_likelihood(const List &inputs, const List &observed_data)
{
  NumericVector y = observed_data["data"];
  double precision = inputs["precision"];
  return sum(Rcpp::dnorm(y, 0.0, 1.0/sqrt(precision), TRUE));
}

// [[Rcpp::export]]
XPtr<EvaluateLogLikelihoodPtr> store_evaluate_log_likelihood()
{
  return(XPtr<EvaluateLogLikelihoodPtr>(new EvaluateLogLikelihoodPtr(&evaluate_log_likelihood)));
}


///////////////////////////////////////////
// Simulate from model.                  //
///////////////////////////////////////////

// [[Rcpp::export]]
List simulate_model(const List &inputs, const List &observed_data)
{
  NumericVector y = observed_data["data"];
  double precision = inputs["precision"];
  NumericVector output = Rcpp::rnorm(y.length(), 0.0, 1.0/sqrt(precision));

  //Rcpp::Rcout << "Std: " << inputs[0]  << std::endl;
  //Rcpp::Rcout << "Mean: " << mean(output)  << std::endl;
  //Rcpp::Rcout << "Std: " << sd(output)  << std::endl;
  return List::create(Named("data") = output);
}

// [[Rcpp::export]]
XPtr<SimulateModelPtr> store_simulate_model()
{
  return(XPtr<SimulateModelPtr>(new SimulateModelPtr(&simulate_model)));
}

// [[Rcpp::export]]
arma::colvec summary_statistics(const List &observed_data)
{
  arma::colvec y = observed_data["data"];

  //Rcpp::Rcout << "Std: " << inputs[0]  << std::endl;
  //Rcpp::Rcout << "Mean: " << mean(output)  << std::endl;
  //Rcpp::Rcout << "Std: " << sd(output)  << std::endl;
  return y;
}

// [[Rcpp::export]]
XPtr<SummaryStatisticsPtr> store_summary_statistics()
{
  return(XPtr<SummaryStatisticsPtr>(new SummaryStatisticsPtr(&summary_statistics)));
}
