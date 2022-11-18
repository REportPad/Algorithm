def solution(people, limit):
    people.sort(reverse=True)
    people_size = len(people)
    i=0
    j=people_size-1
    cnt = 0
    temp = 0
    
    check = []
    for k in range(0,people_size):
        check.append(1)
    
    while i < j:
        temp = people[i]
        cnt += 1
        check[i] = 0
        
        while temp + people[j] <= limit:
            temp += people[j]
            check[j] = 0
            j -= 1
        i += 1
        
    for k in range(0, people_size):
        cnt += check[k]

    return cnt
