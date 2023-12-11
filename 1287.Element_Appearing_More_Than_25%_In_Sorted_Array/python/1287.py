from typing import List


def findSpecialInteger(arr: List[int]) -> int:
    length = len(arr)
    count_dict = {}
    for i in range (length):
        if arr[i] in count_dict:
            count_dict[arr[i]] += 1
        else:
            count_dict[arr[i]] = 1
        if count_dict[arr[i]] >= length // 4:
            return arr[i]
