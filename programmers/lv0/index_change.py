def solution(my_string, num1, num2):
    if num1 > num2:
        t = num1
        num1 = num2
        num2 = t
    
    temp = list(my_string)
    t = temp[num1]
    temp[num1] = temp[num2]
    temp[num2] = t
    
    answer = ''.join(map(str, temp))

    return answer
