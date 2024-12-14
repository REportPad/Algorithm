def make_triangle(M,N):
  arr=[]
  for n in range(M,N+1):
    arr.append(n*(n+1)//2)
  return arr

def make_square(M,N):
  arr=[]
  for n in range(M,N+1):
    arr.append(n*n)
  return arr

def make_pentagonal(M,N):
  arr=[]
  for n in range(M,N+1):
    arr.append(n*(3*n-1)//2)
  return arr

def make_hexagonal(M,N):
  arr=[]
  for n in range(M,N+1):
    arr.append(n*(2*n-1))
  return arr

def make_heptagonal(M,N):
  arr=[]
  for n in range(M,N+1):
    arr.append(n*(5*n-3)//2)
  return arr

def make_octagonal(M,N):
  arr=[]
  for n in range(M,N+1):
    arr.append(n*(3*n-2))
  return arr

arr1 = make_triangle(45,140)
arr2 = make_square(32,99)
arr3 = make_pentagonal(26,81)
arr4 = make_hexagonal(23,70)
arr5 = make_heptagonal(21,63)
arr6 = make_octagonal(19,58)
print(arr1[0],arr1[-1])
print(arr2[0],arr2[-1])
print(arr3[0],arr3[-1])
print(arr4[0],arr4[-1])
print(arr5[0],arr5[-1])
print(arr6[0],arr6[-1])

def cyclical_figurate_numbers(arr1,arr2,arr3,arr4,arr5,arr6):
  for a1 in arr1:
    r1 = a1%100
    for a2 in arr2:
      q2 = a2//100
      if r1 != q2:
        continue
      r2 = a2%100
      for a3 in arr3:
        q3 = a3//100
        if r2 != q3:
          continue
        r3 = a3%100
        for a4 in arr4:
          q4 = a4//100
          if r3 != q4:
            continue
          r4 = a4%100
          for a5 in arr5:
            q5 = a5//100
            if r4 != q5:
              continue
            r5 = a5%100
            for a6 in arr6:
              q6 = a6//100
              r6 = a6%100
              q1 = a1//100
              if r5 == q6 and r6 == q1:
                print(a1,a2,a3,a4,a5,a6)
                return a1+a2+a3+a4+a5+a6
  return 0
  
arr_total = []
arr_total.append(arr1)
arr_total.append(arr2)
arr_total.append(arr3)
arr_total.append(arr4)
arr_total.append(arr5)
arr_total.append(arr6)

import itertools
permutations = list(itertools.permutations(range(6)))

for a in permutations:
  cy = cyclical_figurate_numbers(arr_total[a[0]],arr_total[a[1]],arr_total[a[2]],arr_total[a[3]],arr_total[a[4]],arr_total[a[5]])
  if cy > 0:
    print(a,cy)
