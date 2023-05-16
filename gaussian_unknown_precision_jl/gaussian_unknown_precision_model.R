R_interface_to_julia_dnorm = function(y,m,s,use_log=TRUE)
{
  sum = 0
  for (i in 1:length(y))
  {
    sum = sum + my_dnorm(as.double(y[i]),as.double(m),as.double(s),as.logical(use_log))
  }
  return(sum)
}
