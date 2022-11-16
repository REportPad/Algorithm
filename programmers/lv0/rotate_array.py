def solution(numbers, direction):
    answer = []
    numbers_size = len(numbers)
    
    if direction == "right":
        t = numbers[-1]
        for i in range(0,numbers_size-1):
            numbers[numbers_size-i-1] = numbers[numbers_size-i-2]
        numbers[0] = t
    else:
        t = numbers[0]
        for i in range(0,numbers_size-1):
            numbers[i] = numbers[i+1]
        numbers[-1] = t
    
    answer = numbers
    return answer
