import math

def id34():
    n=10
    x = 0
    while(1):
        list0 = list(map(int, str(n)))
        s = 0
        
        for i in range(0, len(list0)):
            s = s + math.factorial(list0[i])
        
        if(s == n):
            x = x + n
            print(n, x)
            
        n = n + 1
