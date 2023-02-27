#include <vector>

using namespace std;



bool isPalindrome(int x) {
    if (x == 0) return true;
    if (x < 0)  return false;
    vector<int> reg;


    int temp = x;
    int num;
    int digit = 0;

    while (temp >= 10) {
        num = temp % 10;
        digit++;
        temp = temp / 10;
        reg.push_back(num);
    }
    digit++;
    num = temp;
    reg.push_back(num);

    int size = reg.size();


    for (int i = 0; i < size / 2; ++i) {
        if (reg[i] != reg[size - i - 1]) {
            return false;
        }
        else {
            continue;
        }
    }
    return true;



}