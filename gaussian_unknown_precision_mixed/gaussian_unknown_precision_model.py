import numpy as np
from scipy.stats import lognorm
from scipy.stats import norm

def my_rlnorm(n,m,s):
  return lognorm.rvs(s=s, loc=m, scale=1, size=n)
