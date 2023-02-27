#include <vector>
#include <string>

using namespace std;


bool isValid(string s) {
    int a[3];
    for (int i = 0; i < 3; ++i) {
        a[i] = 0;
    }
    vector<char> stack;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            a[0]++;
            stack.push_back('(');
        }
        if (s[i] == '[') {
            a[1]++;
            stack.push_back('[');
        }
        if (s[i] == '{') {
            a[2]++;
            stack.push_back('{');
        }
        if (s[i] == ')') {
            a[0]--;
            if (stack.empty())   return false;
            if (stack.back() != '(') {
                return false;
            }
            else {
                stack.pop_back();
            }
        }
        if (s[i] == ']') {
            a[1]--;
            if (stack.empty())   return false;
            if (stack.back() != '[') {
                return false;
            }
            else {
                stack.pop_back();
            }
        }
        if (s[i] == '}') {
            a[2]--;
            if (stack.empty())   return false;
            if (stack.back() != '{') {
                return false;
            }
            else {
                stack.pop_back();
            }
        }
        if (a[0] < 0 || a[1] < 0 || a[2] < 0) {
            return false;
        }
    }

    if (a[0] != 0 || a[1] != 0 || a[2] != 0) {
        return false;
    }

    else {
        return true;
    }

}