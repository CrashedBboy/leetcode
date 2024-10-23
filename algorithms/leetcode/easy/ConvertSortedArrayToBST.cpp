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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        appendChildren(nums, 0, nums.size()-1, root);

        return root;
    }

private:
    TreeNode* root;

    void appendChildren(vector<int>& nums, int start, int end, TreeNode* parent) {

        if (start > end) {
            return;
        }

        int center = (start + end)/2;

        TreeNode* newNode = new TreeNode(nums[center]);

        if (parent == NULL) {
            root = newNode;
        }
        else {
            if (newNode->val <= parent->val) {
                parent->left = newNode;
            }
            else {
                parent->right = newNode;
            }
        }
        appendChildren(nums, start, center-1, newNode);
        appendChildren(nums, center+1, end, newNode);
    }
};