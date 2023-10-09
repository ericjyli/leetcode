#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {

    // dp[idx] is the cost to reach from start this idx
    vector<int> dp(cost.size(), INT_MAX);
    dp[0] = 0;
    dp[1] = 0;

    // compute the cost to reach i
    for (int i = 2; i < cost.size(); ++i) {
        for (int j = 0; j < 2; ++j) {
            dp[i] = min((dp[i - 2] + cost[i - 2]), (dp[i - 1] + cost[i - 1]));
        }
    }

    return min((dp[cost.size() - 1] + cost[cost.size() - 1]), (dp[cost.size() - 2] + cost[cost.size() - 2]));
}

int main() {
    vector<int> cost1 = {10, 15, 20};
    cout << "cost1: " << minCostClimbingStairs(cost1) << endl;

    return 0;
}