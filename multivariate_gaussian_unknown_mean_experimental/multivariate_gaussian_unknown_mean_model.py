from jax.scipy.stats import multivariate_normal
import jax.numpy as jnp
import numpy
from jax import grad, jit
from functools import reduce
from jax import vmap

def logpdf_func(mu,datum):
  Sigma = 1.0*jnp.identity(2)
  Sigma.at[1,1].set(1000000.0)
  mu = jnp.array(mu)
  return jit(multivariate_normal.logpdf)(datum, mu, Sigma)

def log_llhd_core(mu,y):
  logp = jit(vmap(logpdf_func,(None,0), 0))(mu,y)
  return sum(logp)

def my_log_llhd(parameters,data):
  return log_llhd_core(parameters["mu"],data["y"])

def my_grad_log_llhd(variable,parameters,data):
  return numpy.array(jit(grad(log_llhd_core, argnums=0))(parameters["mu"],data["y"]))
