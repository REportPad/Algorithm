from math import gcd, lcm

class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        n=len(nums)
        if n == 1:
            return nums
        if n == 2:
            l=lcm(nums[0],nums[1])
            if gcd(nums[0],nums[1]) > 1:
                return [l]
            else:
                return nums
        
        i=0
        while i < len(nums)-1:
            g=gcd(nums[i],nums[i+1])
            # print(i,nums,g)
            if g > 1:
                l=lcm(nums[i],nums[i+1])
                nums.insert(i, l)
                del nums[i+1]
                del nums[i+1]
                if i > 0:
                    i-=1
            else:
                i+=1
        return nums
