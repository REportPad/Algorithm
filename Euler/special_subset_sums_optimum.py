import itertools

def is_special_sum_set(s):
    # 모든 부분집합을 구합니다
    subsets = []
    for i in range(1, len(s) + 1):
        subsets.extend(itertools.combinations(s, i))

    # 조건 1: 부분집합의 합이 같으면 안됨
    subset_sums = set()
    for subset in subsets:
      subset_sum = sum(subset)
      if subset_sum in subset_sums:
        return False
      subset_sums.add(subset_sum)

    # 조건 2: 더 큰 부분집합은 항상 더 큰 합을 가짐
    for a, b in itertools.combinations(subsets, 2):
        if len(a) > len(b) and sum(a) <= sum(b):
            return False
        if len(b) > len(a) and sum(b) <= sum(a):
            return False

    return True

# n = 7 최적 특수 합집합 찾기
best_sum = float('inf')
best_set = None

# 초기 추정값 기반 범위 설정
for candidate in itertools.combinations(range(20, 50), 7):
    if is_special_sum_set(candidate):
        current_sum = sum(candidate)
        if current_sum < best_sum:
            best_sum = current_sum
            best_set = candidate

print("최적 특수 합집합 (n=7):", best_set)
print("합계:", best_sum)
print("집합 문자열:", ''.join(map(str, best_set)))
