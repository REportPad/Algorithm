def id33():
    for i in range(11,100):
        for j in range(10,i):
            s1 = str(i)
            s2 = str(j)
            x = j/i
            
            #delete same numbers
            flg = False
            for a in range(0,2):
                for b in range(0,2):
                    if(s1[a] == s2[b] and s1[a] != '0' and s2[b] != '0'):
                        t1 = s1[1-a]
                        t2 = s2[1-b]
                        flg = True
                        break
                if(flg): break

            #check output
            if(flg):
                int1 = int(t1)
                int2 = int(t2)
                if(int1 != 0):
                    y = int2/int1
                    if(x == y):
                        print(j,'/',i)
