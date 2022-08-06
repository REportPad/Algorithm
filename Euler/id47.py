import math

def prime_factorization(x):
    if(x == 2 and x == 3): return x
    i = 2
    j = 0
    d = []
    m = int(math.sqrt(x))

    while(x > 1):
        if(x%i == 0):
            d.append(i)
            x = x/i
            
        else:
            i = i + 1
            
    result = list(set(d))
    return result

def id47(num, a):
    cnt = 0
    
    while(cnt < num):
        d = prime_factorization(a)
        
        if(len(d) == num):
            cnt = cnt + 1
            a = a + 1
        else:
            a = a + 1
            cnt = 0
    
    print(a - 1)
