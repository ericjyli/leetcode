#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct TreeNode_with_depth {
    struct TreeNode *node;
    int depth;

    TreeNode_with_depth(TreeNode *cur_node, int node_depth) : 
        node(cur_node), depth(node_depth) {};
};

int minDepth(TreeNode* root) {
    if (!root)  return 0;
    if (!root -> left && !root -> right)   return 1;
    
    queue<TreeNode_with_depth *> node_queue;

    if (root -> left) {
        struct TreeNode_with_depth *left_node = new TreeNode_with_depth(root -> left, 2);
        node_queue.push(left_node);

    }  
    if (root -> right) {
        struct TreeNode_with_depth *right_node = new TreeNode_with_depth(root -> right, 2);
        node_queue.push(right_node);
    } 
    while (true) {
        TreeNode_with_depth *popped_node = node_queue.front();
        node_queue.pop();

        if (!popped_node -> node -> left && !popped_node -> node -> right) {
            return popped_node -> depth;
        }

        if (popped_node -> node -> left) {
            int val = popped_node -> depth + 1;
            struct TreeNode_with_depth *next_node = new TreeNode_with_depth(popped_node -> node -> left, val);
            node_queue.push(next_node);
        }

        if (popped_node -> node -> right) {
            int val = popped_node -> depth + 1;
            struct TreeNode_with_depth *next_node = new TreeNode_with_depth(popped_node -> node -> right, val);
            node_queue.push(next_node);
        }
    
    }
}

int main() {
    struct TreeNode *root = new TreeNode(2);
    struct TreeNode *left = new TreeNode(3);
    struct TreeNode *left_left = new TreeNode(4);
    struct TreeNode *left_left_left = new TreeNode(5);
    struct TreeNode *left_4 = new TreeNode(6);

    root -> left = left;
    left -> left = left_left;
    left_left -> left = left_left_left;
    left_left_left -> left = left_4;

    int ans = minDepth(root);
    cout << ans << endl;



    return 0;
}