#include "parameters.h"

Parameters::Parameters()
{
}

Parameters::~Parameters()
{

}

void Parameters::operator=(const Parameters &another)
{
  if(this == &another){ //if a==a
    return;
  }

  this->make_copy(another);
}

Parameters* Parameters::duplicate(void)const
{
  return( new Parameters(*this));
}

void Parameters::make_copy(const Parameters &another)
{

}

arma::colvec& Parameters::operator[](const std::string &variable)
{
  return(this->parameters[variable]);
}

arma::colvec Parameters::operator[](const std::string &variable) const
{
  boost::unordered_map< std::string, arma::colvec>::const_iterator found =  this->parameters.find(variable);

  if (found != this->parameters.end())
    return(found->second);
  else
    throw std::runtime_error("Parameters::operator[]: variable not found in Parameters.");
}
