def solution(k, m, score):
    answer = 0
    score.sort(reverse=True)
    score_size = len(score)
    
    for i in range(0,score_size//m):
        answer = answer + score[(i+1)*m - 1]*m

    return answer
