#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;



vector<vector<int> > findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map1;
    unordered_map<int, int> map2;
    vector<vector<int> > res;
    res.push_back(vector<int>());
    res.push_back(vector<int>());
    
    for (int i = 0; i < nums1.size(); ++i) {
        pair<int, int> pair1(nums1[i], i);
        map1.insert(pair1);
    }
    for (int i = 0; i < nums2.size(); ++i) {
        pair<int, int> pair2(nums2[i], i);
        map2.insert(pair2);
    }

    for (int i = 0; i < nums1.size(); ++i) {
        auto it = map2.find(nums1[i]);
        if (it == map2.end()) {
            if (find(res[0].begin(), res[0].end(), nums1[i]) == res[0].end()) 
                res[0].push_back(nums1[i]);
        }
    }



    for (int i = 0; i < nums2.size(); ++i) {
        auto it = map1.find(nums2[i]);
        if (it == map1.end()) {
            if (find(res[1].begin(), res[1].end(), nums2[i]) == res[1].end()) 
                res[1].push_back(nums2[i]);
        }
    } 

    return res;

}

int main() {
    vector<int> nums1(3);
    nums1[0] = 1;
    nums1[1] = 2;
    nums1[2] = 3;

    vector<int> nums2(3);
    nums2[0] = 2;
    nums2[1] = 4;
    nums2[2] = 6;

    vector<vector<int> > res = findDifference(nums1, nums2);

    for (int i = 0; i < res[0].size(); ++i) {
        cout << res[0][i] << endl;
    }

    for (int i = 0; i < res[1].size(); ++i) {
        cout << res[1][i] << endl;
    }


}