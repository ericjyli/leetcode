#include <iostream>
#include <string>

using namespace std;

bool backspaceCompare(string s, string t) {

    string new_s;
    string new_t;
    int size;
    if (s.size() > t.size()) {
        size = s.size();
    }
    else {
        size = t.size();
    }

    for (int i = 0; i < size; ++i) {
        if (i >= s.size() && i >= t.size()) {
            break;
        }
        if (i < s.size()) {
            if (s[i] != '#') {
                new_s.push_back(s[i]);
            }
            else {
                if (new_s.size() > 0)
                    new_s.pop_back();

            }
        }
        if (i < t.size()) {
            if (t[i] != '#') {
                new_t.push_back(t[i]);
            }
            else {
                if (new_t.size() > 0)
                new_t.pop_back();

            }
        }
    }    

    return (new_s == new_t);


}

