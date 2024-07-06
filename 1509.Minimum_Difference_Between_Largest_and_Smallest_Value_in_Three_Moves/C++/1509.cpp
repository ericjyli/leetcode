#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minDifference(vector<int>& nums) {
    if (nums.size() <= 3) {
        return 0;
    }

    sort(nums.begin(), nums.end());

    int res = (min((nums[nums.size() - 1] - nums[3]), (nums[nums.size() - 2] - nums[2])));
    res = min(res, (nums[nums.size() - 3] - nums[1]));
    return min(res, (nums[nums.size() - 4] - nums[0]));


}


int main() {
    vector<int> nums1 = {5, 3, 2, 4};

    cout << minDifference(nums1) << endl;
    return 0;
}