#include <vector>

using namespace std;

vector<int> countBits(int n) {
    int count = 0;
    vector<int> ans;
    while (count != (n + 1)) {
        int temp = count;
        int digit = 0;

        while (temp != 0) {
            int odd = temp % 2;
            digit += odd;
            temp = temp / 2;
        }
        ans.push_back(digit);
        count++;
    }

    return ans;
}