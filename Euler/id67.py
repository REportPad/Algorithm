#open file
file = open("C:/project euler/0067_triangle.txt", "r")
strings = file.readlines()
file.close()

#define variables
ssize = len(strings) #100
t = ""
prev_lst = [int(strings[0])]
now_lst = [0]
ans = 0

#init state
k=0
for j in range(0, len(strings[1])):
    if strings[1][j] == ' ':
        now_lst[k] = int(t)
        k+=1
        t = ""
    else:
        t += strings[1][j]
now_lst.append(int(t))
t = ""

now_lst[0] = prev_lst[0]+now_lst[0]
now_lst[1] = prev_lst[0]+now_lst[1]

for i in range(0, len(prev_lst)):
    prev_lst[i] = now_lst[i]
prev_lst.append(now_lst[-1])

#iteration
for i in range(2,ssize):
    k=0
    for j in range(0, len(strings[i])):
        if strings[i][j] == ' ':
            now_lst[k] = int(t)
            k += 1
            t = ""
        else:
            t += strings[i][j]
    
    now_lst.append(int(t))
    t = ""
    
    now_lst[0] = prev_lst[0]+now_lst[0]
    for u in range(1, len(now_lst)-1):
        now_lst[u] = max(prev_lst[u-1]+now_lst[u], prev_lst[u]+now_lst[u])
    now_lst[-1] = prev_lst[-1]+now_lst[-1]

    #prev_lst = now_lst
    for u in range(0, len(prev_lst)):
        prev_lst[u] = now_lst[u]
    prev_lst.append(now_lst[-1])

ans = max(now_lst)
print("max: ",ans)
