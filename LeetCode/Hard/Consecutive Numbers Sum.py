import math

class Solution:
    def consecutiveNumbersSum(self, n: int) -> int:
        x = math.log2(n)
        if x == int(x):
            return 1

        cnt=0
        t = n
        for k in range(2,n):
            if k%2 == 0:
                a = t//k
                b = k>>1
                if a-b+1 < 1:
                    break
                s1 = k*a-b
                s2 = k*a+b
                # print("k,s1,s2:",k,s1,s2)
                if s1 == t:
                    cnt+=1
                    if a-b <= 1:
                        return cnt+1
                elif s2 == t:
                    cnt+=1
                    if a-b+1 <= 1:
                        return cnt+1
            else:#k is odd.
                a = t//k
                b = (k>>1)
                if a-b < 1:
                    break
                s1 = k*a
                # print("k,s1:",k,s1)
                if s1 == t:
                    cnt+=1
                    if a-(k>>1) <= 1:
                        return cnt+1
            # print("k,cnt:",k,cnt)
        return cnt+1
        
