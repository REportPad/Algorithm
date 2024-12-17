from math import sqrt

def sieve(limit):
    """ 에라토스테네스의 체를 사용하여 소수를 구합니다 """
    primes = []
    is_prime = [True] * (limit + 1)
    for p in range(2, limit + 1):
        if is_prime[p]:
            primes.append(p)
            for i in range(p * p, limit + 1, p):
                is_prime[i] = False
    return primes

def totient(n, primes):
    """ 소수를 사용해 Euler의 Totient 함수 계산 """
    result = n
    for p in primes:
        if p * p > n:
            break
        if n % p == 0:
            while n % p == 0:
                n //= p
            result *= (1 - 1 / p)
    if n > 1:  # 남아있는 소인수 처리
        result *= (1 - 1 / n)
    return int(result)

def is_permutation(a, b):
    """ 두 수가 서로 순열인지 확인 """
    return sorted(str(a)) == sorted(str(b))

def find_min_ratio(limit):
    primes = sieve(int(sqrt(limit)) + 1)  # 소수를 구합니다
    min_ratio = float('inf')
    best_n = 0

    for n in range(2, limit):
        phi_n = totient(n, primes)
        if is_permutation(n, phi_n):
            ratio = n / phi_n
            if ratio < min_ratio:
                min_ratio = ratio
                best_n = n
                print(f"n = {n}, phi(n) = {phi_n}, ratio = {ratio:.6f}")

    return best_n, min_ratio

# 실행
limit = 10_000_000
result_n, result_ratio = find_min_ratio(limit)
print(f"\n최적의 n: {result_n}, 최소 비율: {result_ratio:.6f}")
