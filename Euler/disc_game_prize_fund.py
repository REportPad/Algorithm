from collections import Counter

# 중복을 피하면서 순열 생성하는 재귀 함수
def unique_permutations(counter, prefix, length, result):
  if len(prefix) == length:
    result.append(tuple(prefix))
    # print(result)
    return

  for item in counter:
    # print('item,counter[item],prefix',item,counter[item],prefix)
    if counter[item] > 0:
      counter[item] -= 1
      prefix.append(item)
      unique_permutations(counter, prefix, length, result)
      prefix.pop()
      counter[item] += 1

def disc_game_prize_fund(N):
  p = []
  for i in range(2,N+2):
    p.append(1/i)#1/2,1/3,1/4,...
  # print(p)

  #0 lose
  ret = 1
  for a in p:
    ret *= a#(1,1,1,...,1)

  arr = [1]*N
  for k in range(0,(N-1)//2):
    # print('k:',k)
    arr[k] = 0
    counter = Counter(arr)
    result = []
    unique_permutations(counter, [], len(arr), result)
    for perm in result:
      x = list(perm)
      t=1
      for i in range(0,N):
        t *= abs(1-p[i]-x[i])
      ret += t
  return ret
