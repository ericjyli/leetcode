#include <vector>
#include <unordered_map>

using namespace std;

int equalPairs(vector<vector<int>>& grid) {
    unordered_map<int, vector<int>> row, col;

    int size = grid.size();
    for (int i = 0; i < size; ++i) {
        vector<int> temp_row = grid[i];
        pair<int, vector<int>> temp_pair(i, temp_row);
        row.insert(temp_pair);
    }

    for (int i = 0; i < size; ++i) {
        vector<int> temp_col;
        for (int j = 0; j < size; ++j) {
            temp_col.push_back(grid[j][i]);
        }
        pair<int, vector<int>> temp_pair(i, temp_col);
        col.insert(temp_pair);
    }

    int count = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (row[i] == col[j]) {
                count++;
            }
        }
    }

    return count;
}