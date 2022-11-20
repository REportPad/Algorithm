def solution(s):
    s_size = len(s)
    if s_size == 1:
        return s
    
    if s_size == 2:
        if s[0] == s[1]:
            return ""
        else:
            return s
    
    answer = ""
    s_sort = sorted(s)
    
    i=0
    if s_sort[i] != s_sort[i+1]:
            answer = answer + s_sort[i]

    i=1
    while i < s_size-1:
        if s_sort[i] != s_sort[i+1] and s_sort[i] != s_sort[i-1]:
            answer = answer + s_sort[i]
        i += 1
    
    if s_sort[i] != s_sort[i-1]:
        answer = answer + s_sort[i]

    return answer
