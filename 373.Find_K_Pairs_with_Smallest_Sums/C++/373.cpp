#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct PairComparator {
    bool operator()(const vector<int>& lhs, const vector<int>& rhs) const {
        return (lhs[0] + lhs[1]) < (rhs[0] + rhs[1]);
    }
};

vector<vector<int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<vector<int>, vector<vector<int> >, PairComparator> pq;

    for (int i = 0; i < nums1.size(); ++i) {
        for (int j = 0; j < nums2.size(); ++j) {
            int sum = nums1[i] + nums2[j];
            vector<int> tempPair;
            tempPair.push_back(nums1[i]);
            tempPair.push_back(nums2[j]);
            if (pq.size() < k) {
                pq.push(tempPair);
            }
            else if (sum < (pq.top()[0] + pq.top()[1])) {
                pq.pop();
                pq.push(tempPair);
            }
            else {
                break;
            }
            

        }
    }


    vector<vector<int> > res;
    // int size = nums1.size() * nums2.size();
    // if (size >= k) {
    //     size = k;
    // }
    // for (int i = 0; i < size; ++i) {
    //     res.push_back(pq.top());
    //     pq.pop();
    // }
    while (!pq.empty()) {
        res.push_back(pq.top());
        pq.pop();
    }

    return res;
}




int main() {
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;

    vector<vector<int> > res = kSmallestPairs(nums1, nums2, k);
    for (int i = 0; i < res.size(); ++i) {
        printf("[%d, %d]\n", res[i][0], res[i][1]);
    }


    return 0;
}