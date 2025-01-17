from scipy.special import comb
def under_the_rainbow(n,r,color):
  #n=70, r=20, color=7
  total = comb(n,r)
  p = 1-comb(n-10,r)/total
  return color*p
