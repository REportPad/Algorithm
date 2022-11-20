def solution(my_string):
    temp = my_string
    temp_size = len(temp)
    
    i=0
    j=0
    while i < temp_size:
        d = temp[i]
        j=i+1
        while j < temp_size:
            if d == temp[j]:
                temp = temp[:j] + temp[j+1:]
                temp_size -= 1
            else:
                j += 1
        i += 1
        
    return temp
