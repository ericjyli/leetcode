#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int countCharacters(vector<string>& words, string chars) {
    unordered_map<char, int> char_map;
    for (int i = 0; i < 26; ++i) {
        char_map.insert(pair<char, int>('a' + i, 0));
    }

    for (int i = 0; i < chars.length(); ++i) {
        char_map[chars[i]]++;
    }

    int res = 0;
    for (int i = 0; i < words.size(); ++i) {
        unordered_map<char, int> temp_map(char_map);
        bool valid_word = true;
        for (int j = 0; j < words[i].length(); ++j) {
            temp_map[words[i][j]]--;
            if (temp_map[words[i][j]] < 0) {
                valid_word = false;
                break;
            }
        }
        if (valid_word) {
            res += words[i].length();
        } 
    }

    return res;
}

int main() {
    vector<string> words1 = {"cat","bt","hat","tree"};
    string chars1 = "atach";
    int res1 = countCharacters(words1, chars1);

    cout << "res1: " << res1 << endl;
}
