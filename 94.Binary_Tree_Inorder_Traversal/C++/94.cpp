#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traverseHelper(TreeNode* node, vector<int> &res);

vector<int> inorderTraversal(TreeNode* root) {

    vector<int> res;

    traverseHelper(root, res);

    return res;
    
}


void traverseHelper(TreeNode* node, vector<int> &res) {
    if (!node)  return;
    traverseHelper(node -> left, res);
    res.push_back(node -> val);
    traverseHelper(node -> right, res);

}
