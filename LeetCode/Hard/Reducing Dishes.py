def dot_product(arr,w):
    t = 0
    for i in range(0,len(arr)):
        t += arr[i]*w[len(arr)-1-i]
    return t

class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort(reverse=True)
        s_max = satisfaction[0]
        w = [1,2]
        k=2
        while k <= len(satisfaction):
            t=dot_product(satisfaction[:k],w)
            if t > s_max:
                s_max = t
            else:
                return max(s_max,0)
            k+=1
            w.append(k)
        # print(w,k)
        return max(s_max,0)
