
def isAnagram(s: str, t: str) -> bool:
    
    dict_s = {}
    if len(s) != len(t):
        return False
    for i in range (len(s)):
        if s[i] not in dict_s:
            dict_s[s[i]] = 1
        else:
            dict_s[s[i]] += 1
            
    for i in range (len(t)):
        if t[i] not in dict_s:
            return False
        dict_s[t[i]] -= 1
        if dict[t[i]] < 0:
            return False
    
    return True