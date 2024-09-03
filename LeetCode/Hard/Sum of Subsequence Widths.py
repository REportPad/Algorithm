MOD = 10**9+7
class Solution:
    def sumSubseqWidths(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return 0
        if n == 2:
            return abs(nums[1]-nums[0])

        nums = sorted(nums)
        ans=0
        k=n-1
        c = (1<<k)-1
        c=2**(k)-1
        for i in range(0,k):#0~n-2
            ans += (c*(nums[k-i]-nums[i]))
            c = c - (1<<i)
        return ans%MOD
