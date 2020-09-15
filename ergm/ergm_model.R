require(ergm)

MyFormula = edges+gwdegree(0.8,fixed=TRUE)+gwesp(0.8,fixed=TRUE)

NumberOfStats = 3
NumNodes = 10
IsDirected = FALSE
NumberOfMCMCIterations = 1000 # total number of iterations

ERGMIinputs = matrix(0,number_of_stats)

NumberOfMCMCIterations = 1000 # total number of iterations

PriorMean = 0
PriorSd = 5


ERGMSimulate = function(inputs)
{
  data = simulate(network(NumNodes,directed=IsDirected) ~ MyFormula, coef=inputs, nsim=1, control=control.simulate(MCMC.burnin=NumberOfMCMCIterations,MCMC.interval=1), statsonly = TRUE) # basis=y
  return(data)
}


ERGMPriorsSimulate = function(NumSim)
{
  samp = matrix(0,NumSim,NumberOfStats)
  for (i in 1:NumberOfStats)
  {
    samp[,i] = rnorm(NumSim,PriorMean,PriorSd)
  }
  return(samp)
}
