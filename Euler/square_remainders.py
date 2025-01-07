def square_remainders(N):
  ret = 0
  for a in range(3,N+1):
    r_max = -1
    a2 = a*a
    for n in range(1,2*a+1,2):
      r = ((a-1)**n +(a+1)**n)%a2
      if r > r_max:
        r_max = r
    ret += r_max
    # print(a,r_max,ret)
  return ret
