#include <vector>


using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    const unsigned long size = nums.size();
    vector<vector<int>> all_subsets;

    for (unsigned long i = 0; i < (1 << size); ++i) {
        vector<int> subset;
        for (unsigned long j = 0; j < size; ++j) {
            if (i & (1 << j)) {
                subset.push_back(nums[j]);
            }
        }
        all_subsets.push_back(subset);
    }

    return all_subsets;
}
