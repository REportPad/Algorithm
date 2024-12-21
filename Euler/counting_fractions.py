def euler_totient(n):
  result = n  # 초기값은 n으로 설정
  p = 2       # 소수 시작값
  
  while p * p <= n:
    if n % p == 0:  # p가 n의 소인수인지 확인
      while n % p == 0:
        n //= p
      result -= result // p
    p += 1
  
  if n > 1:  # 마지막 남은 소수가 있을 경우 처리
    result -= result // n
  return result

F=-1
n=10**6
for k in range(1,n+1):
  F += (euler_totient(k))
print(F)
