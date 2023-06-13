class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        front: int
        if (len(nums) == 0):
            return ""
        front = 0
        res = []
        if (len(nums) == 1):
            res.append (f"{nums[front]}")
            return res
        for i in range(len(nums)):
            temp_str = ""
            if (i + 1) == len(nums):
                if (nums[i] != nums[front]):
                    temp_str = f"{nums[front]}->{nums[i]}"
                else: 
                    temp_str = f"{nums[front]}"
                res.append(temp_str)
                break
            if (nums[i + 1] != (nums[i] + 1)):
                if (nums[i] != nums[front]):
                    temp_str = f"{nums[front]}->{nums[i]}"
                else: 
                    temp_str = f"{nums[front]}"
                res.append(temp_str)
                front = i + 1


        return res