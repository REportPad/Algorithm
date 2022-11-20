def isPrime(n):
    if n == 2 and n == 3: return True
    if n%2 == 0: return False

    i=3
    while i < n:
        if n%i == 0:
            return False
        i += 2
    return True
    
def solution(n):
    if n < 4:
        return 0
    
    if n == 4: return 1
    
    #n > 4
    i=5
    prime_cnt = 0
    total = (n - 3) #1,2,3
    while i <= n:
        if isPrime(i) == True:
            prime_cnt += 1
        i += 2
        
    return total - prime_cnt
