def id56():
    ret = -1
    for a in range(1,100):
        for b in range(1,100):
            t = a**b
            sum = 0
            while(t > 0):
                x = t%10
                sum = sum + x
                t = t//10
        
            if(sum > ret):
                ret = sum
    return ret
