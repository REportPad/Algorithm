def solution(food):
    answer = ""
    food_size = len(food)
    
    for i in range(1, food_size):
        t = food[i]//2
        for j in range(0, t):
            answer = answer + str(i)
    temp = answer
    temp_size = len(temp)
    
    answer = answer + "0"
    for i in range(0, temp_size):
        answer = answer + temp[temp_size-1-i]
        
    return answer
