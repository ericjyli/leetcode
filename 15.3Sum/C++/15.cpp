#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    set<vector<int>> res;

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = nums.size() - 1; j > i; --j) {
            for (int k = i + 1; k < j; ++k) {
                int temp_sum = nums[i] + nums[j] + nums[k];
                if (temp_sum == 0) {
                    res.insert({nums[i], nums[j], nums[k]});
                }
                else if (temp_sum > 0) {
                    break;
                }
                else if (temp_sum < 0) {
                    continue;
                }
            }

        }
    }

    vector<vector<int>> res_vec(res.begin(), res.end());

    return res_vec;

}

int main() {
    // vector<int> nums1 = {-1,0,1,2,-1,-4};
    // // {-4, -1, -1, 0, 1, 2}
    // vector<vector<int>> res1 = threeSum(nums1);

    // for (int i = 0; i < res1.size(); ++i) {
    //     for (int j = 0; j < res1[i].size(); ++j) {
    //         cout << res1[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "\n\n";

    // {-1,0,1,2,-1,-4,-2,-3,3,0,4}
    // {-4,-3,-2,-1,0,0,1,2,3,4}
    // Expected: 
    // [[-4,0,4],[-4,1,3],[-3,-1,4],[-3,0,3],[-3,1,2],[-2,-1,3],[-2,0,2],[-1,-1,2],[-1,0,1]]
    // vector<int> nums2 = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    // vector<vector<int>> res2 = threeSum(nums2);


    // for (int i = 0; i < res2.size(); ++i) {
    //     for (int j = 0; j < res2[i].size(); ++j) {
    //         cout << res2[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "\n\n";


    vector<int> nums3 = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<vector<int>> res3 = threeSum(nums3);
    

    for (int i = 0; i < res3.size(); ++i) {
        for (int j = 0; j < res3[i].size(); ++j) {
            cout << res3[i][j] << " ";
        }
        cout << endl;
    }
}