////////////////////////////////////////////////
// Include this file in a user-defined model. //
// DO NOT EDIT!                               //
////////////////////////////////////////////////


#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;


// typedefs for function pointers

#ifndef TYPEDEFS
#define TYPEDEFS

typedef double (*EvaluateLogDistributionPtr)(const List &inputs);

typedef List (*SimulateDistributionPtr)(void);

typedef double (*EvaluateLogLikelihoodPtr)(const List &inputs, const List &observed_data);

typedef double (*EstimateLogLikelihoodPtr)(const List &inputs, const List &observed_data, const List &auxiliary_variables);

typedef List (*SimulateModelPtr)(const List &inputs, const List &observed_data);

typedef List (*SimulateAuxiliaryVariablesPtr)(const List &inputs, const List &observed_data);

typedef XPtr<EstimateLogLikelihoodPtr> (*SetupLikelihoodEstimatorPtr)(const List &inputs, const List &auxiliary_variables);

typedef double (*EvaluateLogABCKernelPtr)(const arma::colvec &simulated_stats,
                const arma::colvec &observed_stats,
                const double &abc_tolerance);

typedef arma::colvec (*SummaryStatisticsPtr)(const List &observed_data);

typedef List (*Getobserved_dataFromSimulationPtr)(const List &simulation);


#endif
