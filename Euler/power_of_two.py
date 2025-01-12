import math
def power_of_two(n,k):
  lower_bound = math.log10(n)-2
  upper_bound = math.log10(n+1)-2
  log2 = math.log10(2)
  j=1
  cnt=0
  while 1:
    fractional_part = (j * log2) % 1
    if fractional_part >= lower_bound and fractional_part < upper_bound:
      cnt+=1
      if cnt == k:
        return j
      j+=195
    j+=1 
