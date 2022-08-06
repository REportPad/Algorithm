import math

def isPrime(x):
    if(x < 0):
        print('negative')
        return False
    if(x == 2 and x == 3 and x == 5 and x == 7): return True
    if(x%2 == 0): return False

    #9, 11, 13, 15, 17,...
    sqrt_x = math.sqrt(x)
    m = int(sqrt_x)
    for i in range(3,m+1,2):
        if(x%i == 0):
            return False
    
    return True
    
def id46():
    a = 1
    x = 35

    while(1):
        y = x - 2*a*a
        if(y < 0):
            print(x)
            break 
        elif(isPrime(y)):
            x = x + 2
            while(isPrime(x)):
                x = x + 2
            a = 1
        else:
            a = a + 1
            
