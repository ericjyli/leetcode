from typing import List

def getCommon(nums1: List[int], nums2: List[int]) -> int:
    i = 0
    j = 0
    while True:
        if nums1[i] == nums2[j]:
            return nums1[i]
        if (i + 1) == len(nums1) and (j + 1) != len(nums2):
            j += 1
        elif (j + 1) == len(nums2) and (i + 1) != len(nums1):
            i += 1
        elif (i + 1) == len(nums1) and (j + 1) == len(nums2):
            return -1
        elif nums1[i] > nums2[j]:
            j += 1
        elif nums1[i] < nums2[j]:
            i += 1
    