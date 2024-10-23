// [idea]
// use recursion to find node P and Q
// in each recursion step: set three flags:
// 1. middle: the current node is either P or Q
// 2. left: P or Q is in the left branch
// 3. right: P or Q is in the right branch


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // initialize
        lca = NULL;

        bool foo = findNode(root, p, q);

        return lca;
    }


private:

    TreeNode* lca;

    bool findNode(TreeNode* root, TreeNode* p, TreeNode* q) {

        // the indicator to stop recursion
        if (lca != NULL) {
            return false;
        }

        // boundry
        if (root == NULL) {
            return false;
        }

        bool middle = false , left = false , right = false;

        left = findNode(root->left, p, q);
        right = findNode(root->right, p, q);
        if (root == p || root == q) {
            middle = true;
        }

        // when two of the three flags are true: the current is LCA
        if ((middle + left + right) == 2) {
            lca = root;
        }
         
        return (middle + left + right) > 0;
    }
};