def mergeAlternately(word1: str, word2: str) -> str:
    i = 0
    j = 0
    res = ''
    turn1 = True
    while True:
        if turn1:
            if i < len(word1):
                res += word1[i]
                i += 1
            turn1 = False
        elif not turn1:
            if j < len(word2):
                res += word2[j]
                j += 1
            turn1 = True
        if len(res) == len(word1) + len(word2):
            return res