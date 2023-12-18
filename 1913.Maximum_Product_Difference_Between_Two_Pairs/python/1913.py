from typing import List
from sys import maxsize

def maxProductDifference(nums: List[int]) -> int:

    subarr = nums[0:4]
    subarr.sort()
    
    for i in range (4, len(nums)):
        if nums[i] > subarr[3]:
            subarr[2] = subarr[3]
            subarr[3] = nums[i]
        elif nums[i] > subarr[2]:
            subarr[2] = nums[i]
        elif nums[i] < subarr[0]:
            subarr[1] = subarr[0]
            subarr[0] = nums[i]
        elif nums[i] < subarr[1]:
            subarr[1] = nums[i]
            
    return subarr[3] * subarr[2] - subarr[0] * subarr[1]