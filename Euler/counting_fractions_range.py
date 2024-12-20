def counting_fractions_range(n):
  a, b, c, d = 0, 1, 1, n  # Start with 0/1 and 1/n
  cnt=0
  while c <= n:
    t= c/d
    if t >= 1/2:
      break

    if t > 1/3 and t < 1/2:
      cnt+=1
    k = (n + b) // d
    a, b, c, d = c, d, k * c - a, k * d - b
  return cnt

n = 12000
print(counting_fractions_range(n))
