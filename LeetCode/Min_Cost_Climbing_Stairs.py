class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        csize = len(cost)
        if csize == 2:
            return min(cost)
       
        #pay[n] = min(pay[n-1], pay[n-2]) + cost[n]
        pay = [cost[0], cost[1]]

        for i in range(0, csize-2):
            t = min(pay[i], pay[i+1]) + cost[i+2]
            pay.append(t)
        
        return min(pay[-1], pay[-2])
