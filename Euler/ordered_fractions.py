def ordered_fractions(D,K):
  arr = [0,0]
  max_value = -1
  for d in range(D,0,-1):
    for n in range(int(d*K),d):
      t = n/d
      if t > K:
        break
      elif t < K and max_value < t:
        max_value = n/d
        arr[0] = n
        arr[1] = d
        print(n,d,max_value)
  return arr
