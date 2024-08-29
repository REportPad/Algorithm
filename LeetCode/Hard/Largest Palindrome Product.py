MOD = 1337

class Solution:
    def largestPalindrome(self, n: int) -> int:
        if n == 1:
            return 9
        
        if n%2 == 0:
            a = 0
            for i in range(0,n):
                a += (9*10**(i))
            
            b = ""#91,9901,999001,99990001
            for i in range(0,n//2):
                b += "9"
            for i in range(0,n//2-1):
                b += "0"
            b+="1"
            b = int(b)
            # print(a,b)
            return (a*b)%MOD

        max_num = 10**n -1
        min_num = 10**(n-1)
        for num in range(max_num, min_num-1, -1):
            palindrome = int(str(num) + str(num)[::-1])

            for i in range(max_num, int(math.sqrt(palindrome))-1, -1):
                if palindrome%i == 0 and len(str(palindrome//i)) == n:
                    return palindrome%MOD
