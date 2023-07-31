#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        if (s.length() == 0)    return "";

        int maxLen = 0;
        string res;

        for (int i = 0; i < s.length(); ++i) {
            for (int j = s.length() - 1; j >= 0; --j) {
                if (isPalindrome(s, i, j)) {
                    int len = j - i + 1;
                    if (len > maxLen) {
                        maxLen = len;
                        res = s.substr(i, (j - i + 1));
                    }
                    
                }
            }
        }

        return res;
    }

};

Solution *x = nullptr;

int main(){
    string a = "aaaa";
    string b = x -> longestPalindrome(a);
    cout << b << endl;

    return 0;
}