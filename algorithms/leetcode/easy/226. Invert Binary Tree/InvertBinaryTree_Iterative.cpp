#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        // idea: swap left & right pointers
        // iteratively, using DFS

        if (root == nullptr) { return root; }

        stack<TreeNode*> dfsStack;
        dfsStack.push(root);

        while (!dfsStack.empty()) {
            TreeNode* n = dfsStack.top(); dfsStack.pop();

            if (n != nullptr) {
                swap(n->right, n->left);
                dfsStack.push(n->right);
                dfsStack.push(n->left);
            }
        }

        return root;
    }
};