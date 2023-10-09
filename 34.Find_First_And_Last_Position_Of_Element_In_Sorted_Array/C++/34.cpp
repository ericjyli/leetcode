#include <iostream>
#include <vector>

using namespace std;
/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

*/



vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.size() == 0)   return {-1, -1};
    if (nums.size() == 1) {
        if (nums[0] == target) {
            return {0, 0};
        }
        else {
            return {-1, -1};
        }
    }

    int left = 0;
    int right = nums.size() - 1;



    if (nums[left] > target || nums[right] < target)    return {-1, -1};


    while (left <= right) {
        if (nums[left] < target && nums[right] > target) {
            left++;
            right--;
            continue;
        }
        else if (nums[left] > target || nums[right] < target) {
            return {-1, -1};
        }   
        else if (nums[left] == target && nums[right] > target) {
            right--;

            continue;
        }
        else if (nums[left] < target && nums[right] == target) {
            left++;

            continue;
        }
        else if (nums[left] == target && nums[right] == target) {

            return {left, right};
        }
    }



    return {-1, -1};
}


int main() {
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> res1 = searchRange(nums1, target1);

    for (int i = 0; i < res1.size(); ++i) {
        cout << res1[i] << " ";
    }
    cout << endl;

    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    int target2 = 6;
    vector<int> res2 = searchRange(nums2, target2);
    for (int i = 0; i < res2.size(); ++i) {
        cout << res2[i] << " ";
    }
    cout << endl;  
}
