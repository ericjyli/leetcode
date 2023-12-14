from typing import List

def majorityElement(nums: List[int]) -> int:
    elem_map = {}
    for i in range (len(nums)):
        if nums[i] in elem_map:
            elem_map[nums[i]] += 1
            if elem_map[nums[i]] > len(nums) // 2:
                return nums[i]
        else:
            elem_map[nums[i]] = 1
            if elem_map[nums[i]] > len(nums) // 2:
                return nums[i]
            