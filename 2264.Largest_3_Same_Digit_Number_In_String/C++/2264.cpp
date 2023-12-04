#include <iostream>
#include <string>

using namespace std;

string largestGoodInteger(string num) {
    string res = "";
    for (int i = 2; i < num.length(); ++i) {
        if (num[i] == num[i - 1] && num[i] == num[i - 2]) {
            string temp_res = num.substr(i - 2, 3);
            if (temp_res > res) {
                res = temp_res;
            }
        }
    }

    return res;
}

