#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;


vector<int> sortByBits(vector<int>& arr) {

    sort(arr.begin(), arr.end());
    unordered_map<int, vector<int>> num_mapping;
    set<int> keys;
    for (int i = 0; i < arr.size(); ++i) {
        int num = arr[i];
        int bits = 0;
        while (num > 0) {
            if (num & 0b1) bits++;
            num = num >> 1;
        }
        num_mapping[bits].push_back(arr[i]);
        keys.insert(bits);
    }   

    vector<int> res; 
    vector<int> keys_vec(keys.begin(), keys.end());

    for (int i = 0; i < keys_vec.size(); ++i) {
        for (int j = 0; j < num_mapping[keys_vec[i]].size(); ++j) {
            res.push_back(num_mapping[keys_vec[i]][j]);
        }
    }

    return res; 
}

int main() {
    vector<int> arr1 = {0,1,2,3,4,5,6,7,8};
    vector<int> res1 = sortByBits(arr1);

    for (int i = 0; i < res1.size(); ++i) {
        cout << res1[i] << " ";
    }
    cout << endl;
}