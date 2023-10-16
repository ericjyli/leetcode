#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int maxResult(vector<int>& nums, int k) {

    // First is the index
    // Second is the value
    priority_queue<pair<int, int>> pq;
    
    vector<int> dp(nums.size(), INT_MIN);
    // dp[idx] refers to the score that can get by visiting this idx

    
    // i is the point to start
    // i + j is the destiniation
    // Update dp[i + j] if the new found path is better (Has greater value)
    for (int i = 0; i < nums.size(); ++i) {

        if (pq.empty()) {
            dp[i] = nums[i];
        }
        else {
            while (!pq.empty() && pq.top().second < i - k) {
                pq.pop();
            }
            dp[i] = nums[i] + pq.top().first;
        }


        pq.push({dp[i], i});

    }

    return dp[nums.size() - 1];
}

int main() {
    vector<int> nums1 = {1,-1,-2,4,-7,3};
    int k1 = 2;
    cout << "maxResult1: " << maxResult(nums1, k1) << endl;
}