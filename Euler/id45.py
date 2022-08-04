def id45():
    flg1 = 0
    flg2 = 0
    a = 144
    b = 166
    c = 286
    
    H=-1
    P=-1
    T=-1
    
    while(flg1 == 0 or flg2 == 0):
        H = a*(2*a-1)
        P = b*(3*b-1)/2
        
        if(H == P):
            flg1 = 1
            
        elif(H > P):
            b = b + 1
        else:
            a = a + 1
        
        while(flg1 == 1):
            T = c*(c+1)/2
        
            if(T == P):
                flg2 = 1
                break
            elif(T > P):
                flg1 = 0
                flg2 = 0
                break
            else:
                c = c + 1
        
    
    if(flg1 == 1 and flg2 == 1):
        print(T, ', ', P, ', ', H)
        
