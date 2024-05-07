
def wordPattern(pattern: str, s: str) -> bool:
    word_dict = {}
    words = s.split()
    if len(words) != len(pattern):
        return False
    for i in range(len(pattern)):
        if pattern[i] not in word_dict:
            if words[i] in word_dict.values():
                return False
            word_dict[pattern[i]] = words[i]
        else:
            if word_dict[pattern[i]] != words[i]:
                return False
            
    
    return True