#include <vector>
#include <iostream>
using namespace std;


vector<int> getRow(int rowIndex) {
    vector<int> ctor(rowIndex + 1);
    vector<vector<int> > triangle((rowIndex+1), ctor);

    for (int i = 0; i <= rowIndex; ++i) {   // row
        for (int j = 0; j <= i; ++j) {  // col
            if (i == 0) {
                triangle[i][j] = 1;
            }

            else if (j == 0 || j == i) {
                triangle[i][j] = 1;
            }

            else {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }    
    }

    return triangle[rowIndex];


}



int main() {

    int num = 5;
    vector<int> res = getRow(num);
    for (int i = 0; i <= num; ++i) {
        cout << res[i] << endl;
    }

}