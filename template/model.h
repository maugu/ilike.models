////////////////////////////////////////////////
// Include this file in a user-defined model. //
// DO NOT EDIT!                               //
////////////////////////////////////////////////


#include <Rcpp.h>
using namespace Rcpp;


// typedefs for function pointers

#ifndef TYPEDEFS
#define TYPEDEFS

typedef double (*EvaluateLogDistributionPtr)(const NumericVector &inputs);

typedef NumericVector (*SimulateDistributionPtr)(void);

typedef double (*EvaluateLogLikelihoodPtr)(const NumericVector &inputs, const NumericMatrix &data);

typedef double (*EstimateLogLikelihoodPtr)(const NumericVector &inputs, const NumericMatrix &data, const List &auxiliary_variables);

typedef List (*SimulateModelPtr)(const NumericVector &inputs, const NumericMatrix &data);

typedef List (*SimulateAuxiliaryVariablesPtr)(const NumericVector &inputs, const NumericMatrix &data);

typedef XPtr<EstimateLogLikelihoodPtr> (*SetupLikelihoodEstimatorPtr)(const NumericMatrix &inputs, const List &auxiliary_variables);

typedef double (*EvaluateLogABCKernelPtr)(const NumericVector &simulated_stats,
                const NumericVector &observed_stats,
                const double &abc_tolerance);

typedef NumericVector (*SummaryStatisticsPtr)(const NumericMatrix &data);

typedef NumericMatrix (*GetDataFromSimulationPtr)(const List &simulation);


#endif
