
def isVowel(c: str):
    if len(c) != 1:
        return False
    
    lower_c = c.lower()
    return (lower_c == 'a' or lower_c == 'e' or lower_c == 'i' or lower_c == 'o' or lower_c == 'u')

def halvesAreAlike(s: str) -> bool:
    firstpart, secondpart = s[:len(s)//2], s[len(s)//2:]
    if len(firstpart) != len(secondpart):
        return False
    
    first_count, second_count = 0, 0
    for i in range (len(firstpart)):
        if isVowel(firstpart[i]):
            first_count += 1
        if isVowel(secondpart[i]):
            second_count += 1
            
    return first_count == second_count
