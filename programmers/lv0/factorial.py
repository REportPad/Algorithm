def solution(n):
    ans = 1
    i=1
    while i <= n+1:
        ans = ans * i
        if ans <= n:
            i += 1
        else:
            return i-1
