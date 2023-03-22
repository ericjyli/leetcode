// plus 1
// math

/*
You are given a large integer represented as an integer array digits, 
where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant 
in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.


*/

#include <vector>
using namespace std;


vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    int carry = 1;
    for (int i = 0; i < n; ++i) {
        int num = digits[n - 1 - i];
        num += carry;
        if (num == 10) {
            digits[n - 1 - i] = 0;
            carry = 1;
        }

        else {
            digits[n - 1 - i] = num;
            carry = 0;
        }
    }

    if (carry == 1) {
        digits.push_back(1);
        rotate(digits.rbegin(), digits.rbegin() + 1, digits.rend());
    }

    return digits;
}