class Solution:
    def minOperations(self, nums: List[int], numsDivide: List[int]) -> int:
        g = numsDivide[0]
        for k in numsDivide[1:]:
            g = gcd(g,k)
        
        nums.sort()
        cnt = 0
        for n in nums:
            if g == n or g%n==0:
                return cnt
            else:
                cnt+=1
        return -1
