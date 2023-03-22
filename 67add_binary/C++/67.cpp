#include <string>
#include <iostream>

using namespace std;


string addBinary(string a, string b) {
    if (a == "0") return b;
    if (b == "0") return a;

    string res;
    int len;
    if (a.size() >= b.size()) len = a.size();
    else len = b.size();

    res.resize(len);

    int temp;
    int carry = 0;
    char num;

    for (int i = 0; i < len; ++i) {
        if (i < a.size() && i < b.size()) {
            temp = (a[a.size() - 1 - i] - '0') + (b[b.size() - 1 - i] - '0');
        }

        else if (i < a.size() && (i > b.size() || i == b.size())) {
            temp = (a[a.size() - 1 - i] - '0');
        }
        
        else if ((i > a.size() || i == a.size()) && i < b.size()) {
            temp = (b[b.size() - 1 - i] - '0');
        }

        temp += carry;
        if (temp == 2) {
            carry = 1;
            temp = 0;
        }

        else if (temp == 3) {
            carry = 1;
            temp = 1;
        }

        else {
            carry = 0;
        }

        num = temp + '0';
        res[len - 1 - i] = num;
    }

    if (carry == 1) {
        res.insert(res.begin(), '1');
    }

    return res;
}

int main() {
    string a = "1111";
    string b = "1111";
    string result = addBinary(a, b);
    std::cout << "The result is " << result << std::endl;



    return 0;
}