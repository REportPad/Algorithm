def solution(numbers, k):
    answer = 0
    num_size = len(numbers)
    
    i=1
    cnt = 0
    while cnt < k:
        answer = (i)%num_size
        i += 2
        cnt += 1
        
    return answer
