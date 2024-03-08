from typing import List

def rearrangeArray(nums: List[int]) -> List[int]:
    positive = []
    negative = []
    res = []

    for i in range (len(nums)):
        if nums[i] > 0:
            positive.append(nums[i])
        else:
            negative.append(nums[i])

    p = 0
    n = 0
    for i in range(len(nums)):
        if i % 2 == 0:
            res.append(positive[p])
            p += 1
        else:
            res.append(negative[n])
            n += 1
    return res