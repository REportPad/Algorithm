def prime(n):
    if(n == 1): return 2
    if(n == 2): return 3
    if(n == 3): return 5
    if(n == 4): return 7
    p = 7
    cnt = 4
    
    while(cnt != n):
        p = p + 2
        flg = 1
   
        for i in range(3,p+1, 2):
            j = i*i
            if(j > p): break
            if(p%i == 0):
                flg = 0
                break
        
        if(flg == 1):
            cnt = cnt + 1
            flg = 0
            
    return p
  
def isPrime(n):
    if(n == 2): return 1
    for i in range(3,n,2):
        if(n%i == 0):
            return 0
    return 1

def id50(i,x):
    s = 0
    while(i < x):
        s = s + prime(i)
        t = isPrime(s)
        print(i, prime(i), s, t)
        i = i+1
        
        
