from typing import List

def sortedSquares(nums: List[int]) -> List[int]:
    for i in range (len(nums)):
        nums[i] = pow(nums[i], 2)
    
    nums.sort()
    return nums

