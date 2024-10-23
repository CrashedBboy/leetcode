#include <iostream>
#include <algorithm>

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
    int diameterOfBinaryTree(TreeNode* root) {
        
        int maxPathLength = 0;
        int dummy = maxDepth(root, maxPathLength);

        return maxPathLength;
    }

private:
    int maxDepth(TreeNode* root, int& maxPathLength) {

        if (root == nullptr) {
            return 0;
        }

        int rightDepth = maxDepth(root->right, maxPathLength);
        int leftDepth = maxDepth(root->left, maxPathLength);
        int length =  rightDepth + leftDepth;
        if (length > maxPathLength) {
            maxPathLength = length;
        }

        return 1 + max(rightDepth, leftDepth);
    }
};