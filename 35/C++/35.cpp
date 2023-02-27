/*
Given a sorted array of distinct integers and a target value, 
return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/


#include <vector>

using namespace std;


int searchInsert(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); ++i) {
        if (target < nums[i] || target == nums[i]) {
            return i;
        }
    }

    return (nums.size());

}
