#include <vector>

using namespace std;

int heightChecker(vector<int>& heights) {
    vector<int> counting(100);
    vector<int> sorted_arr(heights.size());

    for (int i = 0; i < heights.size(); ++i) {
        counting[heights[i] - 1]++;
    }

    int idx = 0;
    for (int i = 1; i <= 100; ++i) {
        for (int j = 0; j < counting[i - 1]; ++j) {
            sorted_arr[idx] = i;
            ++idx;
        }
    }

    int res = 0;
    for (int i = 0; i < heights.size(); ++i) {
        if (heights[i] != sorted_arr[i]) {
            ++res;
        }
    }

    return res;


}
