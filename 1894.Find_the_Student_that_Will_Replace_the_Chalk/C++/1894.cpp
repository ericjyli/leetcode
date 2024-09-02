#include <vector>
using namespace std;

int chalkReplacer(vector<int>& chalk, int k) {
    int i = 0;

    uint64_t sum = 0;
    for (int i = 0; i < chalk.size(); ++i) {
        sum += chalk[i];
    }
    k = k % sum;


    while (1) {
        if (k >= chalk[i]) {
            k -= chalk[i];
            if (i == chalk.size() - 1) {
                i = 0;
            }
            else {
                ++i;
            }
        }
        else {
            return i;
        }
    }
}