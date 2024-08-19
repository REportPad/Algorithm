class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        g = nums[0]
        for k in nums[1:]:
            g = gcd(g,k)
        
        return g==1
