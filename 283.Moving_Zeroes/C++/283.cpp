#include <iostream>
#include <vector>

using namespace std;


void moveZeroes(vector<int>& nums) {
    int z = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) {
            z++;
        } 
        else {
            nums[i - z] = nums[i];
        }
    }

    for (int i = nums.size() - z; i < nums.size(); ++i) {
        nums[i] = 0;
    }
}

int main() {
    vector<int> arr = {0,1,0,3,12};
    moveZeroes(arr);

    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}