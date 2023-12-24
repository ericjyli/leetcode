
def minOperations(s: str) -> int:
    start1 = 0
    start0 = 0
    
    # start 0
    for i in range(len(s)):
        if i % 2 == 0:
            if s[i] == '1':
                start0 += 1
            elif s[i] == '0':
                start1 += 1
        if i % 2 == 1:
            if s[i] == '0':
                start0 += 1
            elif s[i] == '1':
                start1 += 1
    
    
    return min(start0, start1)
        
