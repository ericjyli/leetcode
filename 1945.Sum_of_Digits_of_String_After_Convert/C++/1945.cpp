#include <string>
#include <vector>
#include <iostream>
using namespace std;


int getLucky(string s, int k) {
    vector<int> res;

    for (int i = 0; i < s.length(); ++i) {
        int temp = s[i] - 'a' + 1;
        res.push_back(temp);
    }

    string res_str;
    for (int i = 0; i < res.size(); ++i) {
        res_str.append(to_string(res[i]));
    }
    cout << "res_str: " << res_str << endl;

    int temp_res = 0;
    for (int i = 0; i < k; ++i) {
        temp_res = 0;
        for (int j = 0; j < res_str.length(); ++j) {
            temp_res += (res_str[j] - '0');
        }
        res_str = to_string(temp_res);
        
    }

    return temp_res;



}

int main() {
    string s = "leetcode";
    int k = 2;

    cout << "res: " << getLucky(s, k) << endl;

    return 0;
}