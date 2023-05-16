import numpy as np
from scipy.stats import lognorm
from scipy.stats import norm

def my_rnorm(n):
  return norm.rvs(size=n)

def my_dlnorm(tau,m,s,l):
  if (l==True):
    return lognorm.logpdf(tau,m,s)
  else:
    return lognorm.pdf(tau,m,s)

def my_rlnorm(n,m,s):
  return lognorm.rvs(s=s, loc=m, scale=1, size=n)

def my_dnorm(y,m,s,l):
  if (l==True):
    return norm.logpdf(y,m,s)
  else:
    return norm.pdf(y,m,s)
