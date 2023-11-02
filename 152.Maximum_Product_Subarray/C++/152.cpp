#include <iostream>
#include <vector>

using namespace std;


int maxProduct(vector<int>& nums) {

    int size = nums.size();
    int minProduct = nums[0], maxProduct = nums[0], res = nums[0];
    for(int i = 1; i < size; ++i) {
        if(nums[i] < 0) swap(minProduct, maxProduct);
        maxProduct = max(maxProduct*nums[i], nums[i]);
        minProduct = min(minProduct*nums[i], nums[i]);
        res = max(res, maxProduct);
    }
    return res;
}

int main() {
    vector<int> nums1 = {2,3,-2,4};
    int res1 = maxProduct(nums1);
    cout << "res1: " << res1 << endl;

    vector<int> nums2 = {3,-1,4};
    int res2 = maxProduct(nums2);
    cout << "res2: " << res2 << endl; 

    vector<int> nums3 = {2,-5,-2,-4,3};
    int res3 = maxProduct(nums3);
    cout << "res3: " << res3 << endl;
}