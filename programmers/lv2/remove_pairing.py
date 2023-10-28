from collections import deque
def solution(s):
    deq = deque()
    N=len(s)
    for i in range(0,N):
        if len(deq) == 0:
            deq.append(s[i])
        elif deq[-1] == s[i]:
            deq.pop()
        else:
            deq.append(s[i])
    if len(deq) == 0:
        return 1
    return 0
