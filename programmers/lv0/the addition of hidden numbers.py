def solution(my_string):
    answer = 0
    i=0
    my_string_size = len(my_string)
    temp = []
    cnt = 0
    
    while i < my_string_size:        
        if ord(my_string[i]) >= 48 and ord(my_string[i]) <= 57:
            temp.append(ord(my_string[i])-48)
            cnt += 1
        else:
            if cnt == 1:
                answer += temp[0]
                temp = []
                cnt = 0
            else:
                j=0
                while j < len(temp):
                    answer += temp[j]*pow(10,len(temp)-j-1)
                    j+=1
                temp = []
                cnt = 0
        i += 1
    
    if cnt == 1:
        answer += temp[0]
    else:
        j=0
        while j < len(temp):
            answer += temp[j]*pow(10,len(temp)-j-1)
            j+=1
            
    return answer
