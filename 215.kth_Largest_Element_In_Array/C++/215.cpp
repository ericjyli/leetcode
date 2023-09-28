#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;

    for (int i = 0; i < nums.size(); ++i) {
        pq.push(nums[i]);
    }

    for (int i = 0; i < k - 1; ++i) {
        pq.pop();
    }

    return pq.top();
}


int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int res = findKthLargest(nums, k);

    cout << res << endl;

    return 0;
}