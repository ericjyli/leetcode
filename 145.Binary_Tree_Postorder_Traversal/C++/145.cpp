#include <vector>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

void postorder(struct TreeNode* node, vector<int> &res)
{
    if (node == nullptr)
        return;

    // First recur on left subtree
    postorder(node->left, res);

    // Then recur on right subtree
    postorder(node->right, res);

    // Now deal with the node
    res.push_back(node->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    postorder(root, res);

    return res;
}