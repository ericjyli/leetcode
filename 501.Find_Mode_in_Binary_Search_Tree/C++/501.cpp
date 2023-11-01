#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorderTraverse(TreeNode* node, unordered_map<int, int> &val_count) {
    if (!node)  return;
    inorderTraverse(node -> left, val_count);
    if (val_count.find(node -> val) == val_count.end()) {
        val_count.insert({node -> val, 1});
    }
    else {
        val_count[node -> val]++;
    }

    inorderTraverse(node -> right, val_count);
}


vector<int> findMode(TreeNode* root) {
    unordered_map<int, int> val_count;
    inorderTraverse(root, val_count);

    int mode_count = 0;
    vector<int> res;
    for (auto it = val_count.begin(); it != val_count.end(); ++it) {
        if (it -> second > mode_count) {
            mode_count = it -> second;
            res.clear();
            res.push_back(it -> first);
        }
        else if (it -> second == mode_count) {
            res.push_back(it -> first);
        }

    }

    return res;
}

