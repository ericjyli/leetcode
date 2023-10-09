#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct greater_pair {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};


vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater_pair> pq;

    for (int i = 0; i < mat.size(); ++i) {
        int count = 0;
        for (int j = 0; j < mat[i].size(); ++j) {
            count += mat[i][j];
        }
        pq.push({count, i});
    }
    vector<int> res;
    for (int i = 0; i < k; ++i) {
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
    
    
}
    
