#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

void postorder(struct Node* node, vector<int> &res)
{
    if (node == NULL)
        return;

    // First recur on left subtree

    for (int i = 0; i < node->children.size(); ++i) {
       postorder(node->children[i], res);
    }

    // Now deal with the node

    res.push_back(node->val);
}

vector<int> postorder(Node* root) {
    vector<int> res;

    postorder(root, res);

    return res;
}

