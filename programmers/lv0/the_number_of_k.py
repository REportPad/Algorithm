def solution(i, j, k):
    t_string = ""
    
    while i <= j:
        t = str(i)
        t_string = t_string + t
        i += 1
    
    u=0
    k_str = str(k)
    cnt = 0
    while u < len(t_string):
        if t_string[u] == k_str:
            cnt += 1
        u += 1
    
    return cnt
