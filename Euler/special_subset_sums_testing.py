from itertools import combinations

def get_subsets(s):
  s = list(s)  # set을 리스트로 변환
  n = len(s)
  subsets = []
  
  for i in range(1 << n):  # 2^n 가지 경우의 수
    subset = {s[j] for j in range(n) if (i & (1 << j)) > 0}
    subsets.append(subset)
  return subsets

def is_condition1(set1,set2):
  if sum(set1) == sum(set2):
    return False
  return True

def is_condition2(set1,set2):
  if len(set1) > len(set2) and sum(set1) <= sum(set2):
    return False
  if len(set1) < len(set2) and sum(set1) >= sum(set2):
    return False
  return True

def special_subset_sums_testing(set0):
  subset = get_subsets(set0)
  subset = subset[1:len(subset)-1]

  for a,b in combinations(subset, 2):
    flg1 = is_condition1(a,b)
    flg2 = is_condition2(a,b)
    if flg1==False or flg2==False:
      # print(a,b,flg1,flg2)
      return False
  return True

total=0
with open('0105_sets.txt', 'r', encoding='utf-8') as file:
  line = file.readline()
  while line:
    numbers = [int(num) for num in line.strip().split(',')]
    set0 = set(numbers)
    line = file.readline()

    if special_subset_sums_testing(set0):
      total += sum(set0)
      # print('total:',total,numbers)
  print('total:',total)
