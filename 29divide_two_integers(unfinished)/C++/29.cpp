#include <cmath>
#include <iostream>
using namespace std;

int divide(int dividend, int divisor) {
    int res = 0;
    if (divisor == 1) return dividend;
    if (divisor == -1) {
        if (dividend == INT_MAX)    return (INT_MIN + 1);
        if (dividend == INT_MIN)    return INT_MAX;
        else    return -dividend;
    }
    if (dividend == divisor)    return 1;

    if (divisor == 0) return INT_MAX;

    bool neg = false;
    if (divisor < 0) {
        neg = !neg;
    }
    if (dividend < 0) {
        neg = !neg;
    }


    int compensate = 0;
    if (dividend == INT_MIN)   {
        dividend = INT_MAX;
        compensate = 1;
    }
    else     dividend = abs(dividend);
    
    
    if (divisor == INT_MIN)     return 0;
    else    divisor = abs(divisor);
    
    while (dividend > divisor || dividend == divisor) {
        dividend -= divisor;
        dividend += compensate;
        compensate = 0;
        res++;
    }
    if (neg) {
        res = 0 - res;
    }

    return res;
}


int main() {
    int dividend = -2147484648;
    int divisor = -1;

    int result = divide(dividend, divisor);

    cout << result << endl;
}