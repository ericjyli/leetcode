#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
Given an array of integers arr and an integer d. In one step you can jump from index i to index:

i + x where: i + x < arr.length and  0 < x <= d.
i - x where: i - x >= 0 and  0 < x <= d.
In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).

You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.

Notice that you can not jump outside of the array at any time.

Example 1:

Input: arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
Output: 4
Explanation: You can start at index 10. You can jump 10 --> 8 --> 6 --> 7 as shown.
Note that if you start at index 6 you can only jump to index 7. You cannot jump to index 5 because 13 > 9. You cannot jump to index 4 because index 5 is between index 4 and 6 and 13 > 9.
Similarly You cannot jump from index 3 to index 2 or index 1.
Example 2:

Input: arr = [3,3,3,3,3], d = 3
Output: 1
Explanation: You can start at any index. You always cannot jump to any index.
Example 3:

Input: arr = [7,6,5,4,3,2,1], d = 1
Output: 7
Explanation: Start at index 0. You can visit all the indicies. 
 
*/


int maxJumps(vector<int>& arr, int d) {
    int arr_length = arr.size();
    vector<pair<int, int>> temp_vector;

    for (int i = 0; i < arr_length; ++i) {
        pair<int, int> temp_pair(arr[i], i);
        temp_vector.push_back(temp_pair);
    }

    sort(temp_vector.begin(), temp_vector.end(), greater<pair<int, int>>());
    // for (int i = 0; i < arr_length; ++i) {
    //     cout << temp_vector[i].first << " ";
    // }
    // cout << endl;

    // dp is a nested arrary
    // dp[i][j] records if it is possible to jump from i to j 
    vector<int> dp(arr_length, 1);

    for (int i = 0; i < arr_length; ++i) {
        // o_i is the index in the original arr
        int o_i = temp_vector[i].second;
        for (int x = 1; x <= d; ++x) {
            // i is where we are
            // o_i +- x is where we want to jump to
            if (o_i - x < 0 || arr[o_i - x] >= arr[o_i]) {
                break;
            }
            dp[o_i - x] = max(1 + dp[o_i], dp[o_i - x]);
        }     
        for (int x = 1; x <= d; ++x) {
            if (o_i + x >= arr_length || arr[o_i + x] >= arr[o_i]) {
                break;
            }
            dp[o_i + x] = max(1 + dp[o_i], dp[o_i + x]);
        }
    }

    int max_jump = 1;
    for (int i = 0; i < arr_length; ++i) {
        if (dp[i] > max_jump) {
            max_jump = dp[i];
        }
    }

    return max_jump;
}

int main() {
    vector<int> arr1 = {6,4,14,6,8,13,9,7,10,6,12};
    int d1 = 2;

    cout << maxJumps(arr1, d1) << endl;
}