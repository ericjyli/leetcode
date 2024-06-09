#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

*/
int numDecodings(string s) {
    vector<int> dp(s.length() + 1, 0);
    
    if (s[0] == '0')  return 0;
    dp[0] = 1;          // there is only one way to decode an empty string
    dp[1] = 1;

    for (int i = 2; i <= s.length(); ++i) {
        // if the current character is not '0', add the
        // number of ways to decode the substring without
        // the current character
        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }

        // if the substring of the current and previous
        // characters is a valid two-digit number, add the
        // number of ways to decode the substring without
        // the current and previous characters
        if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
            dp[i] += dp[i - 2];
        }
    }

    return dp[s.length()];

}