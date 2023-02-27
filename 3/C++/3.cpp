#include <string>
#include <unordered_map>

using namespace std;

/*
Given a string s, find the length of the longest 
substring
 without repeating characters.
 */


int lengthOfLongestSubstring(string s) {


        if (s.size() == 1) return 1;
        // key: each char in the string
        // result: the index of the char
        unordered_map<char, int> m;
        int len = 0;
        int maxlen = 0;
        
        for (int i = 0; i < s.size(); ++i) {

            if (m.find(s[i]) != m.end()) {  // duplicate is found
                if (len > maxlen) {
                    maxlen = len;
                }
                len = 0;
                i = m[s[i]];
                m.clear();
                
                continue;

            }

            len++;
            m[s[i]] = i;
        }
        
        if (len > maxlen) {
            maxlen = len;
        }

        return maxlen;

    }