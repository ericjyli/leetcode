from typing import List

def minOperations(nums: List[int]) -> int:
    
    num_dict = {}
    for i in range (len(nums)):
        if nums[i] in num_dict:
            num_dict[nums[i]] += 1
        else:
            num_dict[nums[i]] = 1
    
    res = 0
    
    for key in num_dict:
        if num_dict[key] == 1:
            return -1
        elif num_dict[key] == 2 or num_dict[key] == 3:
            res += 1
        else:
            res += num_dict[key] // 3
            if num_dict[key] % 3 != 0:
                res += 1
                
                
    return res


if __name__ == '__main__':
    nums1 = [2,3,3,2,2,4,2,3,4]
    print(minOperations(nums1))
    
    