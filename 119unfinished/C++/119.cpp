#include <vector>
#include <iostream>
using namespace std;


long long fact(long long n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    else {
        return n * fact(n - 1);
    }
}

vector<int> getRow(int rowIndex) {
    vector<int> res(rowIndex + 1);

    for (int i = 0; i <= rowIndex; ++i) {
        res[i] = (fact(rowIndex) / fact(i) / fact (rowIndex - i));
    }

    return res;
}



int main() {

    cout << fact(13) << endl;
    vector<int> res = getRow(13);
    for (int i = 0; i <= 13; ++i) {
        cout << res[i] << endl;
    }

}