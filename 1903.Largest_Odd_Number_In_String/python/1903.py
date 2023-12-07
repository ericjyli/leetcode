
def largestOddNumber(num: str) -> str:
    for i in range (len(num), 0, -1):
        if int(num[i - 1]) % 2 == 1:
            return num[:i]

    return ""

if __name__ == '__main__':
    print(largestOddNumber('52'))
    