#include <iostream>
#include <vector>

using namespace std;



/*
Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
*/

int lengthOfLIS(vector<int>& nums) {

    // dp[i] is the LIS where nums[i] must be included in the sequence
    // trace all previous numbers
    vector<int> dp(nums.size(), 1);
    int maxLen = 1;

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {       // Checking the length of LIS from 0 to i
            if (nums[j] < nums[i] && dp[i] < dp[j] + 1) {
                dp[i] ++;
            }
        }
        if (maxLen < dp[i]) {
            maxLen = dp[i];
        }
    }

    return maxLen;
} 
                // dp    1  1 1 2 2 3  4  4
int main() {          //      j        i
    vector<int> nums1 = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(nums1) << endl;

    vector<int> nums2 = {4,10,4,3,8,9};
    cout << lengthOfLIS(nums2) << endl;

    vector<int> nums3 = {1, 101, 103, 104, 6, 4, 3, 5, 6, 105, 7, 8, 9, 10};
    // {1}
    // {1, 101}
    // {1, 101, 103}
    // {1, 101, 103, 104}
    // {{1, 101, 103, 104}, {1, 2}}
    // {{1, 101, 103, 104}, {1, 2, 3}}

    cout << lengthOfLIS(nums3) << endl;

    return 0;
}
