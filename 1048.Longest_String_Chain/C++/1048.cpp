#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>

using namespace std;

  
/*
Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.


*/


bool valid_chain (string s1, string s2) {
    int size1 = s1.length();
    int size2 = s2.length();

    if (abs(size1 - size2) != 1) {
        return false;
    }

    string longer_string, shorter_string;
    if (size1 > size2) {
        longer_string = s1;
        shorter_string = s2;
    }
    else {
        longer_string = s2;
        shorter_string = s1;
    }
    size1 = longer_string.length();
    size2 = shorter_string.length();

    int difference = 0;
    int p1 = 0;
    int p2 = 0;

    while(p1 < size1 && p2 < size2) {
        if (longer_string[p1] == shorter_string[p2]) {
            p1++;
            p2++;
            continue;
        }
        else {
            difference++;
            if (difference >= 2) {
                return false;
            }
            if (longer_string[p1 + 1] != shorter_string[p2]) {
                return false;
            }
            p1 ++;
            continue;
        }
    }
    return true;

}
  
int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), [](string &a, string &b) {return a.size() < b.size();});
    int res = 1;

    vector<int> dp(words.size(), 1);
    for (int i = 0; i < words.size(); ++i) {
        for (int j = i + 1; j < words.size(); ++j) {
            if (valid_chain(words[i], words[j])) {
                dp[j] = max(dp[j], dp[i] + 1);
                res = max(dp[j], res);
            }
        }
        
    }

    return res;
}


int main() {
    vector<string> words = {"a", "b", "ab","bac"};
    int res = longestStrChain(words);

    cout << "res: " << res << endl;
    // cout << valid_chain("ab", "bac") << endl;

}

