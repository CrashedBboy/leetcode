#include <iostream>

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
    bool isSymmetric(TreeNode* root) {
        
        return isIdentical(root->left, root->right);
    }

private:
    bool isIdentical(TreeNode* a, TreeNode* b) {

        if (a == nullptr && b == nullptr) {
            return true;
        }
        else if ((a == nullptr) || (b == nullptr)) {
            return false;
        }

        cout << a->val << " vs " << b->val << endl;

        if (a->val != b->val) {
            return false;
        }
        else if (!isIdentical(a->left, b->right)) {
            return false;
        }
        else if (!isIdentical(a->right, b->left)) {
            return false;
        }

        return true;
    }
};