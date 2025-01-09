def is_palindrome(n):
  s = str(n)
  if s == s[::-1]:
    return True
  return False

def palindromic_sums(N):
  M = int(pow(N,0.5))
  arr = [1,4]
  set1 = set()
  set1.add(5)
  for i in range(3,M):
    arr.append(pow(i,2))
    n = arr[-1]
    for j in range(len(arr)-2,-1,-1):
      n += arr[j]
      if n >= N:
        break
      if is_palindrome(n):
        set1.add(n)
  return set1

N=10**8
set1 = palindromic_sums(N)
# print(max(set1))
print('sum:',sum(set1))
