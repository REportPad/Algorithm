import math

def count_divisors_of_square(n: int) -> int:
    """
    n^2 의 약수 개수를 반환.
    (n의 소인수 분해 n = p1^a1 * p2^a2 * ... * pk^ak 이라 하면,
     n^2 = p1^(2a1) * p2^(2a2) * ... * pk^(2ak),
     따라서 약수 개수 tau(n^2) = (2a1 + 1)*(2a2 + 1)*...*(2ak + 1) )
    """
    # n을 소인수분해하여 (소수, 지수)들의 리스트를 구합니다.
    # 예: n=12 -> [(2,2), (3,1)]
    # 그러면 n^2 = 2^4 * 3^2 이므로 약수 개수는 (4+1)*(2+1)=5*3=15
    # count_divisors_of_square(12) -> 15
    result = 1
    temp = n
    # 2부터 시작하여 sqrt(n)까지 나누어가며 소인수분해
    factor = 2
    while factor * factor <= temp:
        exponent = 0
        while temp % factor == 0:
            exponent += 1
            temp //= factor
        if exponent > 0:
            # 소인수 factor^exponent
            result *= (2 * exponent + 1)  # (2a_i + 1)
        factor += 1 if factor == 2 else 2  # 2 이후는 홀수만

    # 만약 마지막에 temp > 1이면 그 자체가 소수
    if temp > 1:
        # 소인수 temp^1
        result *= 3  # (2 * 1 + 1) = 3

    return result

def num_solutions_unordered(n: int) -> int:
    """
    1/x + 1/y = 1/n 의 '순서 없는' 해 (x,y) 쌍의 개수.
    즉 (x,y)와 (y,x)를 같은 해로 본다.
    공식: (tau(n^2) + 1) / 2
    """
    tau_n2 = count_divisors_of_square(n)
    return (tau_n2 + 1) // 2

def solve_exceeds_1000():
    """
    (1/x + 1/y = 1/n)의 순서 없는 해 개수가 1000 개를 넘는
    가장 작은 n 을 찾는다.
    """
    threshold = 1000
    n = 1
    while True:
        # (tau(n^2) + 1)/2 가 1000 초과인지 검사
        if num_solutions_unordered(n) > threshold:
            return n
        n += 1

if __name__ == "__main__":
    answer = solve_exceeds_1000()
    print("최소 n =", answer)
