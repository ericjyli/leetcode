from typing import List

def countBits(self, n: int) -> List[int]:
    res = []
    count = int(0)

    while count < (n + 1):
        temp: int = count
        digit: int = 0

        while temp != 0:
            odd = temp % 2
            digit += odd
            temp = int(temp / 2)
        res.append(digit)
        count += 1

    
    return res