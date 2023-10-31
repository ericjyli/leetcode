
// Given n pairs of parentheses, write a function
// to generate all combinations of well-formatted parentheses

// ((()))

#include <string>
#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


set<string> insertOneParenthesis(string &original_str) {
    set<string> res_set;

    for (int i = 0; i <= original_str.length(); ++i) {
        if (original_str[i] != '(') {
            string temp_str = original_str;
            temp_str.insert(i, "(");
            for (int j = i + 1; j <= temp_str.length(); ++j) {
                if (temp_str[j] != ')') {
                    temp_str.insert(j, ")");
                    res_set.insert(temp_str);
                    temp_str.erase(j, 1);
                }

            }
        }

    }

    return res_set;
}

// 1 <= n <= 8
vector<string> generateParenthesis(int n) {

    vector<vector<string>> dp(n + 1);
    dp[0] = {};
    dp[1] = {"()"};
    if (n == 1) return dp[n];
    dp[2] = {"()()", "(())"};
    if (n == 2) return dp[n];

    // i is the number of parentheses
    for (int i = 3; i <= n; ++i) {
        set<string> temp;
        for (int j = 0; j < dp[i - 1].size(); ++j) {
            string temp_str = dp[i - 1][j];
           
            // add a parentheses for this temp string
            set<string> generated_strs = insertOneParenthesis(temp_str);    
            for (auto it = generated_strs.begin(); it != generated_strs.end(); ++it) {
                temp.insert(*it);
            }
        }
        dp[i].insert(dp[i].end(), temp.begin(), temp.end());
    }


    return dp[n];
}


int main() {

    int n = 3;
    vector<string> res = generateParenthesis(n);
    cout << "Size of res is " << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }

}

