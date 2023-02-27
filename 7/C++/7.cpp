#include <vector>
#include <cmath>

using namespace std;


int reverse(int x) {
    if (x == 0)     return 0;
    bool positive;
    if (x > 0)  positive = true;
    if (x < 0)  positive = false;

    x = abs(x);
    int temp = x;
    int digit = 0;
    int num;

    vector<long long> reg;

    while (temp >= 10) {
        digit += 1;
        
        num = temp % 10;
        temp = temp / 10;
        reg.push_back(num);
    }
    digit += 1;
    num = temp;
    reg.push_back(num);

    long long res = 0;
    for (int i = 0; i < digit; ++i) {
        res += reg[i] * pow(10, (digit - i - 1));
    }

    if (!positive)  res = -res;
    if (res > INT_MAX)  return 0;
    if (res < INT_MIN)  return 0;
    return res;

}