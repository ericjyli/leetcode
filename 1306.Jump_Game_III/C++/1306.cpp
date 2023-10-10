#include <iostream>
#include <vector>

using namespace std;

/*

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 
Example 2:

Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true 
Explanation: 
One possible way to reach at index 3 with value 0 is: 
index 0 -> index 4 -> index 1 -> index 3
Example 3:

Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.

*/
bool canReach(vector<int>& arr, int start) {
    // dp[i] refers to whether i could be visited
    vector<bool> dp(arr.size(), false);
    vector<bool> visited(arr.size(), false);
    bool updated;

    dp[start] = true;

    while (true) {
        updated = false;
        for (int i = 0; i < arr.size(); ++i) {
            if (dp[i] && !visited[i]) {
                updated = true;
                visited[i] = true;

                int idx_back = i - arr[i];
                int idx_forward = i + arr[i];
                if (idx_back >= 0 && idx_back < arr.size()) {
                    dp[idx_back] = true;
                    if (arr[idx_back] == 0) return true;
                }
                if (idx_forward >= 0 && idx_forward < arr.size()) {
                    dp[idx_forward] = true;
                    if (arr[idx_forward] == 0)  return true;
                }
                
            }
        }
        if (!updated)   break;
    }
    return false;  
}


int main() {
    vector<int> arr1 = {4,2,3,0,3,1,2};
    int start1 = 5;
    cout << canReach(arr1, start1) << endl;

    vector<int> arr2 = {0,3,0,6,3,3,4};
    int start2 = 6;
}