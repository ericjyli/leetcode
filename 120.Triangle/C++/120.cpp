#include <vector>

using namespace std;

/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
*/

int minimumTotal(vector<vector<int>>& triangle) {
    if (triangle.size() == 0) {
        return 0;
    }
    if (triangle.size() == 1) {
        return triangle[0][0];
    }

    vector<vector<int>> dp;
    for (int i = 0; i < triangle.size(); ++i) {
        vector<int> temp(triangle[i].size(), 0);
        dp.push_back(temp);
    }

    dp[0][0] = triangle[0][0];

    for (int i = 1; i < triangle.size(); ++i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            if (j == 0) {
                dp[i][j] = triangle[i][j] + dp[i - 1][j];
            }
            else if (j == triangle[i].size() - 1) {
                dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = triangle[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
    }

    int min = INT_MAX;

    for (int i = 0; i < triangle[triangle.size() - 1].size(); ++i) {
        if (dp[triangle.size() - 1][i] < min) {
            min = dp[triangle.size() - 1][i];
        }
    }
    return min;
}