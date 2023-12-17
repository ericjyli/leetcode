from typing import List

def maxProduct(nums: List[int]) -> int:
    nums.sort()
    
    length = len(nums)
    return (nums[length - 2] - 1) * (nums[length - 1] - 1)
