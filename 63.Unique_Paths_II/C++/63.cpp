#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid[0][0] == 1)    return 0;
    for (int i = 1; i <= obstacleGrid.size(); ++i) {
        obstacleGrid[i - 1][0] = 1;
        if (i == obstacleGrid.size())   break;
        if (obstacleGrid[i][0] != 1) {  // is not an obstacle
            continue;            
        }
        else {  // [i][0] is an obstacle
            for (int j = i; j < obstacleGrid.size(); ++j) {
                obstacleGrid[j][0] = 0;
            }
            break;
        }
    }

    for (int i = 1; i <= obstacleGrid[0].size(); ++i) {
        obstacleGrid[0][i - 1] = 1;
        if (i == obstacleGrid[0].size())    break;
        if (obstacleGrid[0][i] != 1) {
            continue;
        }
        else {
            for (int j = i; j < obstacleGrid[0].size(); ++j) {
                obstacleGrid[0][j] = 0;
            }
            break;
        }
    }

    for (int i = 1; i < obstacleGrid.size(); ++i) {
        for (int j = 1; j < obstacleGrid[i].size(); ++j) {
            if (obstacleGrid[i][j] == 1) {
                obstacleGrid[i][j] = 0;
            }
            else {
               obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1]; 
            }
            
        }
    }

    return obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
}


int main() {
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}