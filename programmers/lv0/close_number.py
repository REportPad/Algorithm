def solution(array, n):
    ans = 9999
    best = 9999
    d = 9999
    
    for i in range(0, len(array)):
        d = abs(array[i] - n)
        if d <= best:
            if d == abs(ans - n):
                best = d
                ans = min(ans, array[i])
            else:
                best = d
                ans = array[i]  
    return ans
