from typing import List

def intersection(nums1: List[int], nums2: List[int]) -> List[int]:
    dict1 = {}
    dict2 = {}
    
    for i in range (len(nums1)):
        if nums1[i] not in dict1:
            dict1[nums1[i]] = 1
    
    for i in range (len(nums2)):
        if nums2[i] not in dict2:
            dict2[nums2[i]] = 1
    
    res = []
    for key in dict1.keys():
        if key in dict2.keys():
            res.append(key)
    
    return res