#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        int maxLen = 0;
        int len = 0;
        int front = 0;
        int back = size - 1;
        int startIndex;
        
        for (front = 0; front < size; ++front){
            for (back = (size - 1); back >= 0; --back){
                len = palindromeLength(s, front, back);
                if (len > maxLen){
                    maxLen = len;
                    startIndex = front;
                }        
            }
        }


        //string res = new string;
        char *res = new char[maxLen+1];
        for (int i = 0; i < maxLen; ++i){
            res[i] = s[i + startIndex];
        }
        string r = res;
        return r;
    }

    int palindromeLength (string s, int front, int back){
        int length = 0;
        while (back >= front){
            if (front == back){
                length++;
                break;
            }
            if (s[front] == s[back]){
                front++;
                back--;
                length = length + 2;
            }
            else if (s[front] != s[back]){
                return -1;
            }
        }
        return length;
    }
};

Solution *x = nullptr;

int main(){
    string a = "aaaa";
    string b = x -> longestPalindrome(a);
    cout << b << endl;

    return 0;
}