// Definition for a binary tree node.
#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        TreeNode *temp = root;
        int level = 1;
        int max_sum = INT_MIN;
        int max_level = 1;
        vector<TreeNode *> cur_level;
        cur_level.push_back(root);
        while (true) {
            int value = 0;
            if (cur_level.size() == 0) {
                break;
            }
            for (int i = 0; i < cur_level.size(); ++i) {
                value += cur_level[i] -> val;
            }
            
            if (value > max_sum) {
                max_sum = value;
                max_level = level;
            }
            level++;
            vector<TreeNode *> next_level;
            for (int i = 0; i < cur_level.size(); ++i) {
                TreeNode *temp_node = cur_level[i];
                if (temp_node -> left) {
                    next_level.push_back(temp_node -> left);
                }
                if (temp_node -> right) {
                    next_level.push_back(temp_node -> right);
                }
            } 
            cur_level = next_level;           
        }

        return max_level;
    }
};