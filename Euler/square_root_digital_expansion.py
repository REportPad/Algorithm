from decimal import Decimal, getcontext
def square_root_digital_expansion(N):
  getcontext().prec = 102
  ret = 0
  for n in range(2,N+1):
    m = Decimal(n).sqrt()
    if m == int(m):
      continue
    for i in range(0,100):
      ret += int(m)
      m = m-int(m)
      m = m*10
  return ret
