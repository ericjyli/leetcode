#include <iostream>
#include <vector>

using namespace std;

/*
Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
*/


int maxProfit(vector<int>& prices) {
    // dp[i][j] is the profit bought on day i and sold on day j
    if (prices.size() <= 1) return 0;
    prices.erase( unique(prices.begin(), prices.end()), prices.end());
    vector<vector<int>> dp(prices.size() - 1, vector<int>(prices.size(), 0));

    for (int i = 1; i < prices.size(); ++i) {
        dp[0][i] = max(prices[i] - prices[0], dp[0][i - 1]);
    }

    // i is the start day
    // j is the end day
    for (int i = 1; i < prices.size(); ++i) {
        for (int j = i + 1; j < prices.size(); ++j) {
            if (prices[j] - prices[i] > 0) {
                dp[i][j] = max(dp[i][j - 1], prices[j] - prices[i] + dp[i - 1][i]);
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            
            
        }
    }

    return dp[prices.size() - 2][prices.size() - 1];
}

int main() {
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices1) << endl;

    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << maxProfit(prices2) << endl;

    vector<int> prices3 = {1, 4, 3};
    cout << maxProfit(prices3) << endl;
}