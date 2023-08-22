#include <string>
#include <vector>
#include <iostream>

using namespace std;



string convertToTitle(int columnNumber) {

// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28 
// ...
// ZY -> 701
// ZZ -> 702
// AAA -> 703

    vector<char> ans;

    while (columnNumber > 0) {
        int temp = (columnNumber - 1) % 26;
        ans.push_back ('A' + temp);
        columnNumber = (columnNumber - 1) / 26;
    }

    reverse(ans.begin(), ans.end());
    string ans_str(ans.begin(), ans.end());
    return ans_str;

}

int main() {
    int columnNumber = 27;
    string ans = convertToTitle(columnNumber);

    cout << ans << endl;
}
