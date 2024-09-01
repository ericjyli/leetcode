#include <vector>
using namespace std;

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    vector<vector<int>> res;
    if (original.size() != (m * n)) {
        return res;
    }

    res.resize(m);
    for (int i = 0; i < m; ++i) {
        res[i].resize(n);
    }

    int idx = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            res[i][j] = original[idx];
            idx++;
        }
    }

    return res;
}