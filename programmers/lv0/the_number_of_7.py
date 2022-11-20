def solution(array):
    arr_size = len(array)
    
    i=0
    a_str = ""
    while i < arr_size:
        a_str = a_str + str(array[i])
        i += 1
    
    i=0
    cnt=0
    while i < len(a_str):
        if a_str[i] == '7':
            cnt += 1
        i+=1
        
    return cnt
