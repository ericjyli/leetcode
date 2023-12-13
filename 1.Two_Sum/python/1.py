from typing import List


def twoSum(nums: List[int], target: int) -> List[int]:
    hash_map = {}
    for i in range (len(nums)):
        hash_map[nums[i]] = i

    for i in range (len(nums)):
        if (target - nums[i]) in hash_map and hash_map[target - nums[i]] != i:
            return (i, hash_map[target - nums[i]])