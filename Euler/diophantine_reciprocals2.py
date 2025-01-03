import math

# 필요한 만큼의 소수를 미리 구해둡니다. (에라토스테네스의 체, 여기서는 간단히 하드코딩 예시)
# 실제 문제에서는 더 많은 소수가 필요할 수도 있지만, 상위 몇십 개 소수로도 충분합니다.
primes = [
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97, 101, 103, 107, 109, 113
]

TARGET_DIVISORS = 8_000_000  # d(n^2)가 이 값을 넘어야 함
best_n = None

def backtrack(idx, prev_exp, current_n, divisor_count):
    """
    idx:    현재 할당할 소수의 인덱스(작은 소수부터 차례로 할당)
    prev_exp: 바로 이전 소수에 할당한 지수(a_i)가 몇인지 (내림차순 유지용)
    current_n: 지금까지 만들어진 n의 값
    divisor_count: 지금까지 (2a_i + 1)의 곱 (= d(n^2))
    """
    global best_n
    
    # 만약 현재까지 d(n^2) > 8,000,000을 달성했다면, best_n 갱신 여부 확인
    if divisor_count > TARGET_DIVISORS:
        if best_n is None or current_n < best_n:
            best_n = current_n
        return
    
    # 모든 소수를 사용했다면 중단(더 내려갈 필요 없음)
    if idx >= len(primes):
        return
    
    # 더 탐색해도 이미 best_n보다 커질 가능성이 큰 경우 가지치기
    # (예: current_n > best_n라면 더 클 필요가 없으므로 중단)
    if best_n is not None and current_n > best_n:
        return
    
    # 현재 소수 p
    p = primes[idx]
    
    # exp를 0 ~ prev_exp 까지 할당(내림차순 유지)
    #  예: 이전 소수의 지수가 10이었다면, 이번 소수 지수는 0..10까지만 시도
    for exp in range(prev_exp, -1, -1):
        # 새로 갱신될 divisor_count
        new_divisor_count = divisor_count * (2 * exp + 1)
        
        # 가지치기: 이미 new_divisor_count가 TARGET_DIVISORS를 넘고,
        #           current_n * p^exp가 best_n보다 크다면 굳이 시도할 필요가 없음
        #           하지만 엄밀히는 여기서도 더 세밀한 pruning이 가능.
        
        # n 갱신
        new_n = current_n * (p ** exp)
        
        # 만약 이미 best_n이 있고, new_n이 best_n보다 크다면 break (더 갈 필요 없음)
        if best_n is not None and new_n > best_n:
            break
        
        backtrack(idx + 1, exp, new_n, new_divisor_count)


def solve():
    global best_n
    
    # 시작은 (idx=0, prev_exp=60, current_n=1, divisor_count=1) 정도로 잡아볼 수 있음
    # 지수를 너무 크게 시작하면 탐색 범위가 커지니 적당한 값을 설정.
    # 예시로 60 정도부터 내려가 보도록 합시다.
    backtrack(idx=0, prev_exp=60, current_n=1, divisor_count=1)
    
    return best_n


if __name__ == "__main__":
    result = solve()
    print("가장 작은 n =", result)
