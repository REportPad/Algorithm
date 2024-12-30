from itertools import combinations
from sympy import isprime
from math import sqrt

#1. 소수 생성 (에라토스테네스의 체)
def generate_primes(limit):
    sieve = [True] * (limit + 1)
    sieve[0], sieve[1] = False, False
    for i in range(2, int(sqrt(limit)) + 1):
        if sieve[i]:
            for j in range(i * i, limit + 1, i):
                sieve[j] = False
    return [x for x in range(limit + 1) if sieve[x]]

#2. 두 소수가 연결될 때 소수인지 확인
def are_concatenated_primes(p1, p2):
    return isprime(int(f"{p1}{p2}")) and isprime(int(f"{p2}{p1}"))

#3. 소수 집합 탐색
def find_prime_set(primes, target_size):
  def search(prime_set):
    # print('prime_set:',prime_set)
    if len(prime_set) == target_size:
        return prime_set

    for i, p in enumerate(primes):# for p in primes:
      # print('i,p:',i,p)
      if p > prime_set[-1] and all(are_concatenated_primes(p, q) for q in prime_set):
          result = search(prime_set + [p])
          if result:
            return result
    return None

  idx=1
  for i, p in enumerate(primes):
    result = search([p])
    if result:
      return result

# 메인 함수
def main():
    limit = 10000  # 소수 범위
    target_size = 5  # 목표 크기
    primes = generate_primes(limit)
    primes = primes[1:]
    prime_set = find_prime_set(primes, target_size)
    if prime_set:
        print("최소 합을 가진 소수 집합:", prime_set)
        print("합:", sum(prime_set))
    else:
        print("해당 조건을 만족하는 소수 집합을 찾지 못했습니다.")

if __name__ == "__main__":
    main()
