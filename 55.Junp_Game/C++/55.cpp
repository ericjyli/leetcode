#include <iostream>
#include <vector>

using namespace std;

/*
Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
*/



bool canJump(vector<int>& nums) {
    vector<bool> dp(nums.size(), false);
    dp[0] = true;

    for (int i = 0; i < nums.size(); ++i) {
        if (dp[i]) {
            for (int j = 1; j <= nums[i]; ++j) {
                if ((i + j) < nums.size())
                    dp[i + j] = true;
                else
                    return true;
            }
        }

    }
    return dp[nums.size() - 1];
}


int main() {
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "1: " << canJump(nums1) << endl;
    
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "2: " << canJump(nums2) << endl;


}