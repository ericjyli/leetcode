#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
// Return any possible rearrangement of s or return "" if not possible.


struct CompareChars{
    bool operator()(const pair<int, char> &c1, const pair<int, char> &c2) {
        return c1.first < c2.first;
    }
};

string reorganizeString(string s) {
    int length = s.length();

    int idx = 0;
    vector<int> comp(26);

    for (int i = 0; i < s.size(); ++i) {
        comp[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (comp[i] > (length + 1) / 2) {
            return "";
        }
    }

    priority_queue<pair<int, char>, vector<pair<int, char> >, CompareChars > pq;

    for (int i = 0; i < 26; i++) {
        if (comp[i] > 0) {
            pq.push(make_pair(comp[i], i + 'a'));
        }
    }
    // pq stores the number of characters and the character itself

    string ans = "";

    while (!pq.empty()) {

        pair<int, char> first = pq.top();
        pq.pop();

        pair<int, char> second;
        if (!pq.empty()) {
            second = pq.top();
            pq.pop();
        }
        else {
            if (first.first > 1) {
                return "";
            }
            else {
                ans += first.second;
                break;
            }
        }


        ans += first.second;
        first.first--;
        ans += second.second;
        second.first--;
        

        if (first.first > 0) {
            pq.push(first);
        }
        if (second.first > 0) {
            pq.push(second);
        }


    }

    return ans;




}


int main() {
    string s = "aabbcc";
    string ans = reorganizeString(s);
    cout << ans << endl;
    return 0;
}