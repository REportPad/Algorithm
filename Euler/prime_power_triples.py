def sieve_of_eratosthenes(limit):
  if limit < 2:
    return []
  
  sieve = [True] * (limit + 1)
  sieve[0] = sieve[1] = False  # 0과 1은 소수가 아님
  
  for num in range(2, int(limit**0.5) + 1):
    if sieve[num]:
      for multiple in range(num*num, limit + 1, num):
        sieve[multiple] = False
              
  primes = [num for num, is_prime in enumerate(sieve) if is_prime]
  return primes

def prime_power_triples(N,primes,L):
  set0=set()
  for a in range(0,L):
    A=primes[a]**2
    for b in range(0,L):
      B=primes[b]**3
      for c in range(0,L):
        x = A +B +primes[c]**4
        if x >= N:
          break
        set0.add(x)
  return len(set0)

N=5*10**7
primes = sieve_of_eratosthenes(7100)
L=len(primes)
prime_power_triples(N,primes,L)
