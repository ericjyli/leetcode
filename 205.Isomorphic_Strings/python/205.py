def isIsomorphic(s: str, t: str) -> bool:
    if len(s) != len(t):
        return False 
    map_dict = {}
    for i in range(len(s)):
        if s[i] in map_dict:
            if t[i] != map_dict[s[i]]:
                return False
        else:
            map_dict[s[i]] = t[i]
    
    map_dict.clear()

    for i in range(len(t)):
        if t[i] in map_dict:
            if s[i] != map_dict[t[i]]:
                return False
        else:
            map_dict[t[i]] = s[i]
    

    return True