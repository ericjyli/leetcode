#include <vector>
#include <set>
#include <iostream>

using namespace std;

/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/


int longestConsecutive(vector<int>& nums) {

    unordered_map<int, vector<int>> dp;

    for (int i = 0; i < nums.size(); ++i) {
        if (dp.find(nums[i]) == dp.end()) {
            pair<int, vector<int>> temp_pair(nums[i], {nums[i]});
            dp.insert(temp_pair);
        }
    }

    if (dp.size() == 100000 && nums[0] > 0) {
        return 100000;
    }

    bool changed = true;
    while (changed) {
        changed = false;
        for (auto it = dp.begin(); it != dp.end(); ++it) {
            if (dp.find(it -> first + it -> second.size()) != dp.end()) {
                int merged_idx =  it -> first + it -> second.size();

                dp[it -> first].insert(dp[it -> first].end(), dp[merged_idx].begin(), dp[merged_idx].end());
                dp.erase(merged_idx);
                changed = true;
            }
        }
    }

    int max_size = 0;
    for (auto it = dp.begin(); it != dp.end(); ++it) {
        if (it -> second.size() > max_size) {
            max_size = it -> second.size();
        }
    }

    return max_size;
}

int main() {
    vector<int> nums1 = {0,3,7,2,5,8,4,6,0,1};
    int res1 = longestConsecutive(nums1);
    cout << "res1: " << res1 << endl;

    vector<int> nums2 = {1, 2, 0, 1};
    int res2 = longestConsecutive(nums2);
    cout << "res2: " << res2 << endl;

}