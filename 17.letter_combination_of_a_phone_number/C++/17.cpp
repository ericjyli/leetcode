#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>


using namespace std;



vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.size() == 0)    return res;

    unordered_map<char, vector<char> > hashing;
    vector<char> char2;
    char2.push_back('a');
    char2.push_back('b');
    char2.push_back('c');
    pair<char, vector<char> > pair2('2', char2);

    vector<char> char3;
    char3.push_back('d');
    char3.push_back('e');
    char3.push_back('f');
    pair<char, vector<char> > pair3('3', char3);

    vector<char> char4;
    char4.push_back('g');
    char4.push_back('h');
    char4.push_back('i');
    pair<char, vector<char> > pair4('4', char4);

    vector<char> char5;
    char5.push_back('j');
    char5.push_back('k');
    char5.push_back('l');
    pair<char, vector<char> > pair5('5', char5);

    vector<char> char6;
    char6.push_back('m');
    char6.push_back('n');
    char6.push_back('o');
    pair<char, vector<char> > pair6('6', char6);

    vector<char> char7;
    char7.push_back('p');
    char7.push_back('q');
    char7.push_back('r');
    char7.push_back('s');
    pair<char, vector<char> > pair7('7', char7);

    vector<char> char8;
    char8.push_back('t');
    char8.push_back('u');
    char8.push_back('v');
    pair<char, vector<char> > pair8('8', char8);

    vector<char> char9;
    char9.push_back('w');
    char9.push_back('x');
    char9.push_back('y');
    char9.push_back('z');
    pair<char, vector<char> > pair9('9', char9);

    hashing.insert(pair2);
    hashing.insert(pair3);
    hashing.insert(pair4);
    hashing.insert(pair5);
    hashing.insert(pair6);
    hashing.insert(pair7);
    hashing.insert(pair8);
    hashing.insert(pair9);


    vector<int> count(digits.size(), 0);

    bool done = true;
    while (true) {
        done = true;
        string temp_string;
        for (int i = 0; i < digits.size(); ++i) {
            vector<char> temp_char;
            temp_char = hashing[digits[i]];
            temp_string.push_back(temp_char[count[i]]);
        }
        res.push_back(temp_string);
        for (int i = 0; i < count.size(); ++i) {
            if (count[i] < (hashing[digits[i]].size() - 1)) {
                count[i]++;
                done = false;
                break;
            }
            else {
                if (i != (count.size() - 1)) {
                    count[i] = 0;
                    continue;
                }
            }
        }
        if (done) {
            break;
        }

    }

    return res;


}

int main() {
    string digits = "2345";
    vector<string> res = letterCombinations(digits);

    cout << "The size of res is " << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }


    return 0;
}