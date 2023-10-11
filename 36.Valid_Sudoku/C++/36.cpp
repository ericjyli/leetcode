#include <iostream>
#include <vector> 
using namespace std;


bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<int>> rows(9, vector<int>(9, 0));
    vector<vector<int>> cols(9, vector<int>(9, 0));
    // on row[i], the number of j existing (initially all 0s)
    vector<vector<int>> grids(9, vector<int>(9, 0));

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '1';
                rows[i][num] ++;
                cols[j][num] ++;
                if (i < 3 && j < 3) {
                    grids[0][num]++;
                }
                else if (i >= 3 && i < 6 && j < 3) {
                    grids[1][num]++;
                }
                else if (i >= 6 && j < 3) {
                    grids[2][num]++;
                }
                else if (i < 3 && j >= 3 && j < 6) {
                    grids[3][num]++;
                }
                else if (i >= 3 && i < 6 && j >= 3 && j < 6) {
                    grids[4][num]++;
                }
                else if (i >= 6 && j >= 3 && j < 6) {
                    grids[5][num]++;
                }
                else if (i < 3 && j >= 6) {
                    grids[6][num]++;
                }
                else if (i >= 3 && i < 6 && j >= 6) {
                    grids[7][num]++;
                }
                else if (i >= 6 && j >= 6) {
                    grids[8][num]++;
                }
            }
        }
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (rows[i][j] > 1 || cols[j][i] > 1 || grids[i][j] > 1) {
                return false;
            }
        }
    }
    return true;
}
