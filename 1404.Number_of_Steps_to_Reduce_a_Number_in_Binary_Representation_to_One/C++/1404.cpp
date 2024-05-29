#include <iostream>
#include <string>

using namespace std;


int numSteps(string s) {
    int step = 0;

    while(s != "1") {
        step ++;
        if (s.back() == '0') {
            s.pop_back();
        }
        else if (s.back() == '1') {
            int idx = s.length() - 1;
            int add = 1;
            while (idx >= 0) {
                if (s[idx] == '1') {
                    s[idx] = '0';
                    add = 1;
                    if (idx == 0) {
                        s.insert(0, "1");
                        break;
                    }
                    idx--;
                }
                else if (s[idx] == '0') {
                    s[idx] = '1';
                    break;
                }
            }
        }
    }
    return step;
}