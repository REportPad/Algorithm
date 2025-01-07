def square_remainders(N):#16sec
  ret = 0
  for a in range(3,N+1):
    r_max = -1
    a2 = a*a
    for n in range(1,2*a+1,2):
      r = (pow(a - 1, n, a2) + pow(a + 1, n, a2)) % a2
      if r > r_max:
        r_max = r
    ret += r_max
    # print(a,r_max,ret)
  return ret
