class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        ct = 0
        for i in nums:
            if (i - diff in nums) and (i + diff in nums):
                ct += 1
        return ct
