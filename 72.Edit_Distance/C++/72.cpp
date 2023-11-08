#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 


*/

int minDistance(string word1, string word2) {

    // dp[i][j]
    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));

    dp[0][0] = 0;
    for (int i = 1; i <= word1.length(); ++i) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= word2.length(); ++i) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= word1.length(); ++i) {
        for (int j = 1; j <= word2.length(); ++j) {
            if (word1[i - 1] != word2[j - 1]) {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            else {
                dp[i][j] =  dp[i - 1][j - 1];
            }
        }
    }

    return dp[word1.length()][word2.length()];
}

int main() {
    // string word1_1 = "horse";
    // string word1_2 = "ros";
    // int res1 = minDistance(word1_1, word1_2);
    // cout << "res1: " << res1 << endl;

    // string word2_1 = "intention";
    // string word2_2 = "execution";
    // int res2 = minDistance(word2_1, word2_2);
    // cout << "res2: " << res2 << endl;

    string word3_1 = "zoologicoarchaeologist";
    string word3_2 = "zoogeologist";
    int res3 = minDistance(word3_1, word3_2);
    cout << "res3: " << res3 << endl;
}