def facto(n):
    if n == 1: return 1
    f = 1
    for i in range(2,n+1):
        f *= i
    return f

class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        if n == 1:
            return "1"
        if n == 2:
            if k == 1:
                return "12"
            return "21"
        num = []
        for i in range(1,n+1):
            num.append(str(i))
        t = n-1
        v = k
        f = facto(t)
        arr = []
        q = (v-1)//f
        r = (v-1)%f
        # print("num:",num)
        # print("q,r,f:",q,r,f)
        while t > 0:
            arr.append(num[q])
            del num[q]
            f = f//t
            t-=1
            v = r
            q = (v)//f
            r = (v)%f
            # print("q,r,f:",q,r,f)
        # print(arr)
        ans = ""
        for n in arr:
            ans += str(n)
        ans += num[0]
        return ans
