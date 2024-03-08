#include <vector>
#include <unordered_map>

using namespace std;

int missingNumber(vector<int>& nums) {
    int size = nums.size();

    unordered_map<int, int> num_map;

    for (int i = 0; i < size; ++i) {
        num_map.insert({nums[i], 1});
    }

    for (int i = 0; i <= size; ++i) {
        if (num_map.find(i) == num_map.end()) {
            return i;
        }
    }
    return -1;
}