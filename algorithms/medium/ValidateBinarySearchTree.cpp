#include <iostream>
#include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {

        // idea: convert it into in-order traversal sequence, using stack
        stack<TreeNode*> traverseStack;
        vector<int> inorder;

        TreeNode* current = root;
        while (current != NULL || !traverseStack.empty()) {

            if (current == NULL) {
                current = traverseStack.top();
                inorder.push_back(current->val);
                current = current->right;
                traverseStack.pop();
            }
            else {
                traverseStack.push(current);
                current = current->left;
            }
        }

        for (auto& n : inorder) {
            cout << n << ",";
        }
        cout << endl;

        for (int i = 1; i < inorder.size(); i++) {

            if (inorder[i-1] >= inorder[i]) {
                return false;
            }
        }

        return true;
    }
};