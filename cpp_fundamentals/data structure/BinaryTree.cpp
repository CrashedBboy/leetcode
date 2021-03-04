#include <iostream>
#include <string>
#include <queue>
#include <math>

using namespace std;


class BinaryTreeNode {

    public:

        BinaryTreeNode* left;
        BinaryTreeNode* right;
        int data;

        BinaryTreeNode : data {0}, left {NULL}, right {NULL} () {  }

        BinaryTreeNode : left {NULL}, right {NULL} (int value) {
            data = value;
        }

        BinaryTreeNode (int value, TreeNode* leftChild, TreeNode* rightChild) {
            data = value;
            left = leftChild;
            right = rightChild;
        }
};

class BinaryTree {

    public:

        TreeNode* root;

        BinaryTree (int rootValue) {

            root = new TreeNode(rootValue);
        }

        // construct tree from level-by-level sequence
        BinaryTree (vector<int> nums) {

            if (nums.size() == 0) {
                root = new TreeNode();
                return;
            }

            root = new TreeNode(nums[0]);

            // idea: use queue to store node to be append
            queue<pair<TreeNode*, bool>> parents; // pair <node, append on left?>
            parents.push(pair<TreeNode*, bool> (root, true));
            parents.push(pair<TreeNode*, bool> (root, false));

            for (int i = 1; i < nums.size(); i++) {
                pair<TreeNode*, bool> p = parents.front();

                TreeNode* parentNode = p.first;
                bool appendToLeft = p.second;

                if (parentNode != NULL) {

                    TreeNode* child;
                    if (nums[i] != -1) {
                        child = new TreeNode(nums[i]);
                    } else {
                        child = NULL;
                    }

                    if (appendToLeft) {
                        parentNode->left = child;
                    } else {
                        parentNode->right = child;
                    }

                } else {

                    child = NULL;
                }

                parents.push(pair<TreeNode*, bool> (child, true));
                parents.push(pair<TreeNode*, bool> (child, false));

                parents.pop();
            }
        }

        // construct tree from pre-order sequence and post-order sequence
        BinaryTree (vector<int> preorderSequence, vector<int> inorderSequence) {

        }

        void print () {

            if (root == NULL) {
                cout << "The tree is empty." << endl;
                return;
            }

            int currentLevel = 0;
            int nodeAmountInLevel = 0;
            int levelStartAt = 0;

            vector<int> levelOrderNodes;
            queue<TreeNode*> bfsQueue;
            
            bfsQueue.push(root);

            while (bfsQueue.size() > 0) {

                TreeNode* currentNode = bfsQueue.front();

                if (currentNode != NULL) {
                    bfsQueue.push(currentNode->left);
                    bfsQueue.push(currentNode->right);

                    levelOrderNodes.push(currentNode->data);
                } else {
                    bfsQueue.push(NULL); // virtual left child
                    bfsQueue.push(NULL); // virtual right child

                    levelOrderNodes.push(-1); // use -1 to indicate "NULL"
                }

                nodeAmountInLevel += 1;
                int levelMaxNode = pow(2, currentLevel);

                // if the level if full: check whether they are all NULLs
                if (nodeAmountInLevel == levelMaxNode) {
                    bool isAllNull = true;
                    for (int i = levelStartAt; i < levelStartAt + levelMaxNode; i++) {
                        if (levelOrderNodes[i] != -1) {
                            isAllNull = false;
                            break;
                        }
                    }

                    if (isAllNull) {

                        // not to print this level

                        // stop BFS
                        break;

                    } else {

                        for (int i = levelStartAt; i < levelStartAt + levelMaxNode; i++) {
                            cout << levelOrderNodes[i] << " ";
                        }
                        cout << endl;

                        currentLevel += 1;
                        nodeAmountInLevel = 0;
                        levelStartAt += levelMaxNode;
                    }
                }

                bfsQueue.pop();
            }
        }

        int getMaximumDepth () {

        }

        int getMinimumDepth () {

        }

        TreeNode* searchBFS (TreeNode* node) {

        }

        TreeNode* searchDFS (TreeNode* node) {

        }

        vector<int> getInorderSequence () {

        }

        vector<int> getPreorderSequence () {

        }

        vector<int> getPostorderSequence () {

        }

        vector<int> getLevelSequence () {

        }

    private:

};

int main() {
    return 0;
}