#include <vector>
#include <iostream>
using namespace std;

vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    for (int i = 0; i < k; ++i) {
        pair<int, int> smallest_idx_and_num(-1, INT_MAX);
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] < smallest_idx_and_num.second) {
                smallest_idx_and_num.first = j;
                smallest_idx_and_num.second = nums[j];
            }
        }    
        nums[smallest_idx_and_num.first] = smallest_idx_and_num.second * multiplier;    
    } 

    return nums;
}

