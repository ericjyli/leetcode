#include <vector>

using namespace std;

vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    vector<vector<int>> res((grid.size() - 2), vector<int>((grid.size() - 2), 0));

    for (int i = 0; i < (grid.size() - 2); ++i) {
        for (int j = 0; j < (grid[i].size() - 2); ++j) {
            int max = INT_MIN;
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 3; ++l) {
                    if (grid[i + k][j + l] > max) {
                        max = grid[i + k][j + l];
                    }
                }
            }
            res[i][j] = max;
        }
    }

    return res;
}

