from typing import List

def findDuplicate(nums: List[int]) -> int:
    num_dict = {}
    for i in range(len(nums)):
        if nums[i] in num_dict:
            return nums[i]
        else:
            num_dict[nums[i]] = 1