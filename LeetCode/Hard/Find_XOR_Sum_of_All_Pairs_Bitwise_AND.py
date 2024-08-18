class Solution:
    def getXORSum(self, arr1: List[int], arr2: List[int]) -> int:
        x=0
        for a1 in arr1:
            x ^= a1
        y=0
        for a2 in arr2:
            y ^= a2
        
        return x&y
