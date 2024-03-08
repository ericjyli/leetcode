from typing import List

def maxFrequencyElements(nums: List[int]) -> int:
    num_count = {}
    for i in range (len(nums)):
        if nums[i] in num_count:
            num_count[nums[i]] += 1
        else:
            num_count[nums[i]] = 1
    
    max_freq = 0
    for num_key in num_count:
        if num_count[num_key] > max_freq:
            max_freq = num_count[num_key]

    print(max_freq)
    res = 0
    for num_key in num_count:
        if num_count[num_key] == max_freq:
            res += num_count[num_key]
    
    return res