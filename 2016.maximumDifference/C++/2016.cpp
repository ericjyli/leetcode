#include <vector>

using namespace std;

int maximumDifference(vector<int>& nums) {
    int res = -1;
    int min = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if ((nums[i] - min) > 0 && (nums[i] - min) > res) {
            res = nums[i] - min;
        }
        if (nums[i] < min) {
            min = nums[i];
        }
    }

    return res;

}


