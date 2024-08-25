import math

class Solution:
    def abbreviateProduct(self, left: int, right: int) -> str:
        p=left
        for i in range(left+1,right+1):
            p *= i

        # print(p)
        cnt=0
        while p%10==0:
            p = p//10
            cnt+=1

        psize = int(math.log10(p))+1
        t = p
        if psize > 10:
            a = ""
            b = ""
            for i in range(0,5):
                r = t%10
                b += str(r)
                t = t//10
            b = b[::-1]
            t=p
            for i in range(0,5):
                r = t//(10**(psize-1-i))
                r = r%10
                a += str(r)

            return a+ "..." +b + "e" + str(cnt)
        return str(p) + "e" + str(cnt)
