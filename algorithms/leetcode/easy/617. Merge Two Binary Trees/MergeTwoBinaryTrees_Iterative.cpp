#include <queue>
#include <utility>

typedef pair<TreeNode*, TreeNode*> NodePair;

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// try to solve it iteratively using BFS

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        if (!root1) {
            return root2;
        }

        if (!root2) {
            return root1;
        }

        queue<NodePair> q;
        q.push(NodePair(root1, root2));

        while (!q.empty()) {
            
            NodePair p = q.front(); q.pop();

            TreeNode* node1 = p.first; // will always have value
            TreeNode* node2 = p.second;

            if (node2 == nullptr) {

                // no need to merge any values to node1
                continue;
            }
            else {
            
                // add node2's value to node1
                node1->val += node2->val;

                if (node1->right == nullptr) {
                    node1->right = node2->right;
                    // stop here, no need to dive deeper
                }
                else {
                    // keep dive deeper
                    q.push(NodePair(node1->right, node2->right));
                }

                if (node1->left == nullptr) {
                    node1->left = node2->left;
                }
                else {
                    q.push(NodePair(node1->left, node2->left));
                }
            }
        }

        return root1;
    }
};