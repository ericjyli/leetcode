from typing import List

def isPalindrom(s: str) -> bool:
    return s == s[::-1]

def firstPalindrome(words: List[str]) -> str:
    for i in range(len(words)):
        if isPalindrom(words[i]):
            return words[i]

    return ''