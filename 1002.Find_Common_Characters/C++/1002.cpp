#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

vector<string> commonChars(vector<string>& words) {
    unordered_map<char, priority_queue<int, vector<int>, greater<int>>> wmap(words.size());
    for (int i = 0; i < words.size(); ++i) {
        unordered_map<char, int> word_map;
        for (int j = 0; j < words[i].length(); ++j) {
            if (word_map.find(words[i][j]) == word_map.end()) {
                word_map.insert({words[i][j], 1});
            }
            else {
                word_map[words[i][j]]++;
            }
        }
        for (auto it : word_map) {
            if (wmap.find(it.first) != wmap.end()) {
                wmap[it.first].push(it.second);
            }
            else {
                priority_queue<int, vector<int>, greater<int>> temp_q;
                temp_q.push(it.second);
                wmap.insert({it.first, temp_q});
            }
        }
    }

    vector<string> res;
    for (auto it : wmap) {
        if (it.second.size() == words.size()) {
            for (int i = 0; i < it.second.top(); ++i) {
                string s(1, it.first);
                res.push_back(s);
            }

        }
    }

    return res;
}
