import math

class Solution:
    def findValidSplit(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return -1
        if n == 2:
            if gcd(nums[0],nums[1]) == 1:
                return 0
            return -1
        
        s = 0
        for i in range(n-1,0,-1):
            g1 = gcd(nums[0],nums[i])
            if g1 > 1:
                s=i
                break
        
        prefix = math.prod(nums[:s+1])
        suffix = math.prod(nums[s+1:])
        i=s
        while i < n-1:
            g = gcd(prefix,suffix)
            if g == 1:
                return i
            else:
                for j in range(n-1,s,-1):
                    g1 = gcd(g,nums[j])
                    if g1 > 1:
                        s = j
                        break
                i=s
                prefix = math.prod(nums[:s+1])
                suffix = math.prod(nums[s+1:])
        return -1
