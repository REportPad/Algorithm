def SelfPowers(n):
    x = 0
    for i in range(1,n+1):
        x = x + pow(i,i)
    return x
