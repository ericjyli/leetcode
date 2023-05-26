
// Given n pairs of parentheses, write a function
// to generate all combinations of well-formatted parentheses

// ((()))


#include <string>
#include <vector>
#include <list>
#include <map>
#include <iostream>

using namespace std;

// 1 <= n <= 8
vector<string> generateParenthesis(int n) {
    vector<string> res;
    if (n <= 0) return res;
    pair<char, char> parenthesis('(', ')');



    // n = 3
    // ()()()   3
    // (())()   1
    // ()(())   1
    // ((()))   0

    // n = 4
    //
    // ()()()() 4
    //
    // (())()() 2
    // ()(())() 2
    // ()()(()) 2
    //
    // ((()))() 1
    // ()((())) 1
    //
    // (((()))) 0

    // n = 5
    // ()()()()() 5

    // (())()()() 3
    // ()(())()() 3
    // ()()(())() 3
    // ()()()(()) 3

    // ((()))()() 2
    // ()((()))() 2
    // ()()((())) 2

    // (((())))() 1
    // ()(((()))) 1

    // ((((())))) 0


    // number of single (not nested) parenthesises
    // the index of them



    int single_num = n;
    vector<bool> single(n);
    for (int i = 0; i < n; ++i) {
        single[i] = true;
    }

    while (true) {
        // generate the positions of the single parenthesises
        bool valid = true;
        string temp_str;
        temp_str.resize(n * 2);

        // fill in the single parenthesises first
        for (int i = 0; i < n; ++i) {
            if (single[i]) {
                temp_str[i * 2] = '(';
                temp_str[i * 2 + 1] = ')';
            }
        }

        for (int i = 0; i < n; ++i) {
            if (!single[i]) {
                int start_idx = i;
                while (!single[i] && i < n) {
                    i++;
                }
                i--;
                if (start_idx == i) {
                    valid = false;
                    break;
                }
                else {
                    int j = start_idx * 2;
                    int num = i - j + 1;
                    for (int k = 0; k < num; ++k) {
                        temp_str[j] = '(';
                        j++;
                    }
                    for (int k = 0; k < num; ++k) {
                        temp_str[j] = ')';
                        j++;
                    }
                }
            }
        }


        if (!valid) {
            continue;
        }
        else {
            res.push_back(temp_str);

        }


        // iterate by changing single_num and vector<bool> single
        if (single[n - 1] == false) {
            single_num--;
        }

        else if (single_num == n) {
            single_num = single_num - 2;
        }

        // not changing the number of single nums



    }

    return res;
}


int main() {

    int n = 3;
    vector<string> res = generateParenthesis(n);
    cout << "Size of res is " << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }

}

