def solution(before, after):
    b = sorted(before)
    a = sorted(after)
    if a == b:
        return 1
    
    return 0
