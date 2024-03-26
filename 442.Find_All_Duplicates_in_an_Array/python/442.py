from typing import List

    
def findDuplicates(nums: List[int]) -> List[int]:
    num_dict = {}
    for i in range(len(nums)):
        if nums[i] in num_dict:
            num_dict[nums[i]] += 1
        else:
            num_dict[nums[i]] = 1
    
    res = []
    for num in num_dict:
        if num_dict[num] > 1:
            res.append(num)
    
    return res