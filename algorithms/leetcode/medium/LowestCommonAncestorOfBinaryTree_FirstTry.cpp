// [idea]
// get the travel pathes for the two nodes -> 2 sequences
// compare the sequence and find the last common item



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
        
        vector<TreeNode*> emptyPath;
        findNode(root, p, emptyPath, pSequence);
        findNode(root, q, emptyPath, qSequence);

        TreeNode* lastCommon = NULL;

        int pIdx = 0, qIdx = 0;
        bool stop = false;
        while (!stop && pIdx < pSequence.size() && qIdx < qSequence.size()) {
            
            if (pSequence[pIdx] == qSequence[qIdx]) {

                lastCommon = pSequence[pIdx];

            } else {

                stop = true;
            }
            pIdx += 1; qIdx += 1;
        }

        return lastCommon;
    }


private:

    vector<TreeNode*> pSequence;
    vector<TreeNode*> qSequence;

    void findNode(TreeNode* root, TreeNode* target, vector<TreeNode*> path, vector<TreeNode*>& storeTo) {

        if (root == NULL) {
            return;
        }

        path.push_back(root);

        if (root == target) {

            storeTo = vector<TreeNode*> (path);
            return;

        } else {

            findNode(root->left, target, path, storeTo);
            findNode(root->right, target, path, storeTo);
        }
    }
};