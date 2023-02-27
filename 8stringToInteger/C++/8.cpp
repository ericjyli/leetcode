#include <iostream>
#include <string>
#include <vector>
#include <math.h>


using namespace std;

int myAtoi(string s) {
    bool start = false;
    bool positive = true;
    bool leading_zeros = true;
    vector<int> res;
    for (int i = 0; i < s.size(); ++i) {

        // ignore leading white spaces
        if (!start && s[i] == ' ') {
            continue;
        }

        // return 0 if leading char is not valid
        else if (!start && s[i] != '-' && s[i] != '+' && s[i] != ' ' && (s[i] < '0' || s[i] > '9')) {
            return 0;
        }


        // the leading char is valid
        // start = true

        if (s[i] == '-' && !start) {
            positive = false;
            start = true;
            continue;
        }

        else if (s[i] == '+' && !start) {
            positive = true;
            start = true;
            continue;
        }

        

        else if (s[i] >= '0' && s[i] <= '9') {
            start = true;
            if (s[i] == '0' && leading_zeros) {
                continue;
            }
            leading_zeros = false;
            int temp = s[i] - '0';
            res.push_back(temp);
        }



        else {
            break;
        } 
    }

    long long digit = res.size();
    long long result = 0;

    if (digit > 13) {
        if (positive)   return INT_MAX;
        if (!positive)  return INT_MIN;
    }

    for (int i = 0; i < res.size(); ++i) {
        result += res[i] * pow(10, (digit - i - 1));
    }
    if (!positive) {
        result = -result;
    }

    if (result >= INT_MAX)  return INT_MAX;
    if (result <= INT_MIN)  return INT_MIN;

    int Result = result;

    return Result;
}

int main() {
    string s = "words and 987";
    int a = myAtoi(s);

    cout << "a is " << a << endl;

    return 0;
}
