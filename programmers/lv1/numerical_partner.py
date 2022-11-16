def solution(X, Y):
    X_size = len(X)
    Y_size = len(Y)
    X_arr = []
    Y_arr = []
    
    for i in range(0,10):
        X_arr.append(0)
        Y_arr.append(0)
    
    for i in range(0, X_size):
        X_int = int(X[i])
        X_arr[X_int] = X_arr[X_int]+1
        
    for i in range(0, Y_size):
        Y_int = int(Y[i])
        Y_arr[Y_int] = Y_arr[Y_int]+1
    
    answer = ""
    t = 0
    for i in range(9, -1, -1):
        t = min(X_arr[i], Y_arr[i])
        for j in range(0, t):
            answer = answer + str(i)
    
    if answer == "":
        return "-1"
    elif answer[0] == '0':
        return "0"
    
    return answer
