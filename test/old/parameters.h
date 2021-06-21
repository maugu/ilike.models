// [[Rcpp::depends(BH)]]

#include <RcppArmadillo.h>
using namespace Rcpp;

#include <vector>
#include <boost/unordered_map.hpp>

#ifndef PARAMETERS_H
#define PARAMETERS_H

// At some point, we might need a more flexible container for data and/or parameters.
// At this point, make another class that includes this one.

class Parameters
{

public:

  Parameters();

  virtual ~Parameters();

  arma::colvec& operator[](const std::string &variable);
  arma::colvec operator[](const std::string &variable) const;

  void operator=(const Parameters &another);
  Parameters* duplicate() const;

protected:

  boost::unordered_map< std::string, arma::colvec> parameters;

  void make_copy(const Parameters &another);

};

typedef Parameters Data;

#endif
