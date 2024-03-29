from typing import List

def firstMissingPositive(nums: List[int]) -> int:
    for i in range (len(nums)):
        while nums[i] > 0 and nums[i] <= len(nums) and nums[i] != nums[nums[i] - 1]:
            idx = nums[i] - 1
            nums[i], nums[idx] = nums[idx], nums[i]
    print(nums)

    for i in range (len(nums)):
        if nums[i] != (i + 1):
            return (i + 1)
    
    return (len(nums) + 1)