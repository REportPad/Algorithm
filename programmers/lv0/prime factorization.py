def solution(n):
    i = 2
    ans = []
    
    while i <= n:
        if n%i == 0:
            if len(ans) == 0:
                ans.append(i)
            elif i != ans[-1]:
                ans.append(i)
            n = n//i
        else:
            i += 1
            
    ans.sort()
    
    return ans
