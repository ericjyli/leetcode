from typing import List
from sys import maxsize

def buyChoco(prices: List[int], money: int) -> int:
    min1 = maxsize
    min2 = maxsize
    
    for i in range(len(prices)):
        if prices[i] < min1:
            min2 = min1
            min1 = prices[i]
        elif prices[i] < min2:
            min2 = prices[i]
            
    
    return (money - min1 - min2) if (money - min1 - min2) >= 0 else money
