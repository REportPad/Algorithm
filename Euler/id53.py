import math

def combi(n,r):
    return math.factorial(n)/(math.factorial(r) * math.factorial(n-r))

def id53():
    cnt = 0
    for n in range(1,101):
        for r in range(0,n+1):
            x = combi(n,r)
            if(x > 10**6):
                cnt = cnt + 1
    return cnt
