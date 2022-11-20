def solution(num_list, n):
    num_list_size = len(num_list)
    r = num_list_size//n
    c = n
    arr = [[0 for j in range(c)] for i in range(r)]
    
    for i in range(0,r):
        for j in range(0,c):
            arr[i][j] = num_list[n*i + j]
    
    return arr
