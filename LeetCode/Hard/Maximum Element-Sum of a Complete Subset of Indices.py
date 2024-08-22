class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        n= len(nums)
        if n == 1:
            return nums[0]
        
        m=int(sqrt(n))+1
        sq = []
        for i in range(1,m):
            sq.append(i*i)
        # print(sq)
        ret = 0
        sq_size = len(sq)
        for i in range(0,sq_size):
            ret += nums[sq[i]-1]

        k=1
        while k < n:
            temp = nums[k]#2
            for i in range(1,sq_size):
                if (k+1)*sq[i]-1 < n:
                    temp += nums[(k+1)*sq[i]-1]
                else:
                    break
            ret = max(ret,temp)
            k+=1
        return ret
