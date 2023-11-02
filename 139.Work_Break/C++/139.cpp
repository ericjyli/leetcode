#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


bool wordBreak(string s, vector<string>& wordDict) {
    // dp[i][j] means if the word start from i and end at j can be mixed from the wordDict
    vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));

    unordered_map<string, int> words;
    for (int i = 0; i < wordDict.size(); ++i) {
        words.insert({wordDict[i], i});
    }

    if (words.find(s) != words.end()) {
        return true;
    }

    for (int i = 0; i < s.length(); ++i) {
        for (int j = i; j < s.length(); ++j) {
            string str = s.substr(i, j - i + 1);
            if (words.find(str) != words.end()) {
                dp[i][j] = true;            
                if (i == 0 && j == s.length() - 1) {
                    return true;
                }
            }


        }
    }

    // j is the start index
    // k is the end index of the first string
    for (int j = 0; j < s.length(); ++j) {
        for (int k = 0; k < j; ++k) {
            if (dp[0][k] && dp[k + 1][j]) {
                if (j == s.length() - 1)  return true;
                dp[0][j] = true;
            }
        }
    }
    

    return dp[0][s.length() - 1];

}

int main() {
    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    bool res1 = wordBreak(s1, wordDict1);
    cout << "res1: " << res1 << endl;

    string s2 = "ab";
    vector<string> wordDict2 = {"a", "b"};
    bool res2 = wordBreak(s2, wordDict2);
    cout << "res2: " << res2 << endl;
}

