#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;



int minExtraChar(string s, vector<string>& dictionary) {
    unordered_map<char, int> mp;

    char tmp = 'a';
    for (int i = 0; i < 26; ++i) {
        pair<char, int> tmp_pair(tmp, 0);
        mp.insert(tmp_pair);
        tmp++;
    }

    for (int i = 0; i < s.size(); ++i) {
        mp[s[i]]++;
    }

    for (int i = 0; i < dictionary.size(); ++i) {
        string dict_tmp = dictionary[i];
        for (int j = 0; j < dict_tmp.size(); ++j) {
            if (mp[dict_tmp[j]] != 0) {
                mp[dict_tmp[j]]--;
            }
        }
    }

    int num = 0;
    tmp = 'a';
    for (int i = 0; i < 26; ++i) {
        if (mp[tmp] > 0) {
            num += mp[tmp];
        }
        tmp++;
    }

    return num;
}

int main() {
    string s = "dwmodizxvvbosxxw";
    vector<string> dictionary{"ox","lb","diz","gu","v","ksv","o","nuq","r","txhe","e","wmo","cehy","tskz","ds","kzbu"};

    int ans = minExtraChar(s, dictionary);
    cout << ans << endl;

    return 0;


}