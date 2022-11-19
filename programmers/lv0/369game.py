def solution(order):
    cnt = 0
    
    while order > 0:
        t = order%10
        order = order // 10
        if t%3 == 0 and t > 0:
            cnt += 1
    
    return cnt
