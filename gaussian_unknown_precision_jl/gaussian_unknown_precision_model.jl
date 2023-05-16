import Pkg; Pkg.add("Distributions")
using Random, Distributions

function my_rnorm(n)
  d = Normal()
  rand(d, n)
end

function my_dlnorm(tau,m,s,l)
  μ_for_mean(m1, σ) = log(m1) - σ^2/2
  d = LogNormal(μ_for_mean(m, s), s)
  if (l==true)
    logpdf(d,tau)
  else
    pdf(d,tau)
  end
end

function my_rlnorm(n,m,s)
  μ_for_mean(m1, σ) = log(m1) - σ^2/2
  d = LogNormal(μ_for_mean(m, s), s)
  rand(d, n)
end

function my_dnorm(y,m,s,l)
  d = Normal(m,s)
  if (l==true)
    logpdf(d,y)
  else
    pdf(d,y)
  end
end
