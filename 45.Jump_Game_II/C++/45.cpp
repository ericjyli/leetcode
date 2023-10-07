#include <iostream>
#include <vector>

using namespace std;


/*
Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2

*/

int jump(vector<int>& nums) {
    if (nums.size() <= 1)    return 0;

    vector<int> dp(nums.size(), INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 1; j <= nums[i]; ++j) {
            if ((i + j) < nums.size())
                dp[i + j] = min(dp[i] + 1, dp[i + j]);
        }
    }

    return dp[nums.size() - 1];



}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << jump(nums) << endl;
}