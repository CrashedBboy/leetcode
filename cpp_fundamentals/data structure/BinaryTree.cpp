#include <iostream>
#include <string>
#include <queue>
#include <cmath>

using namespace std;


class BinaryTreeNode {

public:

    BinaryTreeNode() : data{ 0 }, left{ NULL }, right{ NULL }  {  }

    BinaryTreeNode(int value) : left{ NULL }, right{ NULL }  {
        data = value;
    }

    BinaryTreeNode(int value, BinaryTreeNode* leftChild, BinaryTreeNode* rightChild) {
        data = value;
        left = leftChild;
        right = rightChild;
    }

    BinaryTreeNode* left;
    BinaryTreeNode* right;
    int data;
};

class BinaryTree {

public:

    BinaryTreeNode* root;

    BinaryTree(int rootValue) {

        root = new BinaryTreeNode(rootValue);
    }

    // construct tree from level-by-level sequence
    BinaryTree(vector<int> nums) {

        if (nums.size() == 0) {
            root = new BinaryTreeNode();
            return;
        }

        root = new BinaryTreeNode(nums[0]);

        // idea: use queue to store node to be append
        queue<pair<BinaryTreeNode*, bool>> parents; // pair <node, append on left?>
        parents.push(pair<BinaryTreeNode*, bool>(root, true));
        parents.push(pair<BinaryTreeNode*, bool>(root, false));

        for (int i = 1; i < nums.size(); i++) {
            pair<BinaryTreeNode*, bool> p = parents.front();

            BinaryTreeNode* parentNode = p.first;
            bool appendToLeft = p.second;

            BinaryTreeNode* child;
            if (parentNode != NULL) {
                
                if (nums[i] != -1) {
                    child = new BinaryTreeNode(nums[i]);
                }
                else {
                    child = NULL;
                }

                if (appendToLeft) {
                    parentNode->left = child;
                }
                else {
                    parentNode->right = child;
                }

            }
            else {

                child = NULL;
            }

            parents.push(pair<BinaryTreeNode*, bool>(child, true));
            parents.push(pair<BinaryTreeNode*, bool>(child, false));

            parents.pop();
        }
    }

    // construct tree from pre-order sequence and post-order sequence
    BinaryTree(vector<int>& preorderSequence, vector<int>& inorderSequence) {

        // indexes needed for recursion: 
        // - parent node pointer
        // - append to left or right
        // - preorder sequence
        // - preorder subtree sequence starts at
        // - preorder subtree sequence ends at
        // - inorder sequence
        // - inorder subtree sequence starts at
        // - inorder subtree sequence ends at
        

        _buildFromPreorderInorder(NULL, true,
            preorderSequence, 0, preorderSequence.size() - 1,
            inorderSequence, 0, inorderSequence.size() - 1);
    }

    void print() {

        if (root == NULL) {
            cout << "The tree is empty." << endl;
            return;
        }

        int currentLevel = 0;
        int nodeAmountInLevel = 0;
        int levelStartAt = 0;

        vector<int> levelOrderNodes;
        queue<BinaryTreeNode*> bfsQueue;

        bfsQueue.push(root);

        while (bfsQueue.size() > 0) {

            BinaryTreeNode* currentNode = bfsQueue.front();

            if (currentNode != NULL) {
                bfsQueue.push(currentNode->left);
                bfsQueue.push(currentNode->right);

                levelOrderNodes.push_back(currentNode->data);
            }
            else {
                bfsQueue.push(NULL); // virtual left child
                bfsQueue.push(NULL); // virtual right child

                levelOrderNodes.push_back(-1); // use -1 to indicate "NULL"
            }

            nodeAmountInLevel += 1;
            int levelMaxNode = (int)pow(2, currentLevel);

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
                }
                else {

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

    int getMaximumDepth() {
        return _getMaximumDepth(root);
    }

    int getMinimumDepth() {
        return _getMinimumDepth(root);
    }

    BinaryTreeNode* searchBFS(int value) {

        if (root == NULL) {
            return NULL;
        }

        queue<BinaryTreeNode*> bfsQueue;
        bfsQueue.push(root);

        while (!bfsQueue.empty()) {

            BinaryTreeNode* node = bfsQueue.front();

            if (node != NULL) {

                // testing
                cout << node->data << ",";

                if (node->data == value) {
                    return node;
                }
                else {
                    bfsQueue.push(node->left);
                    bfsQueue.push(node->right);
                }
            }

            bfsQueue.pop();
        }

        return NULL;
    }

    BinaryTreeNode* searchDFS(int value) {
        return _dfs(root, value);
    }

    // in-order: left-root-right
    vector<int> getInorderSequence() {

        vector<int> sequence = {};

        _inorderTraverse(root, sequence);

        return sequence;
    }

    // pre-order: root-left-right
    vector<int> getPreorderSequence() {

        vector<int> sequence = {};

        _preorderTraverse(root, sequence);

        return sequence;
    }

    vector<int> getPostorderSequence() {

        vector<int> sequence = {};

        _postorderTraverse(root, sequence);

        return sequence;
    }

    vector<int> getLevelSequence() {

        vector<int> sequence = {};
        vector<int> output = {};

        int currentLevel = 0;
        int nodeAmountInLevel = 0;
        int levelStartAt = 0;

        queue<BinaryTreeNode*> bfsQueue;
        bfsQueue.push(root);

        while (!bfsQueue.empty()) {

            BinaryTreeNode* node = bfsQueue.front();

            if (node != NULL) {
                sequence.push_back(node->data);

                bfsQueue.push(node->left);
                bfsQueue.push(node->right);
            }
            else {
                sequence.push_back(-1);

                bfsQueue.push(NULL); // left child
                bfsQueue.push(NULL); // right child
            }

            nodeAmountInLevel += 1;

            int levelMaxNode = (int)pow(2, currentLevel);

            if (nodeAmountInLevel == levelMaxNode) {

                bool isAllNull = true;
                for (int i = levelStartAt; i < levelStartAt + levelMaxNode; i++) {
                    if (sequence[i] != -1) {
                        isAllNull = false;
                        break;
                    }
                }

                if (isAllNull) {
                    // stop BFS & serialization
                    break;
                }
                else {
                    for (int i = levelStartAt; i < levelStartAt + levelMaxNode; i++) {
                        output.push_back(sequence[i]);
                    }

                    // reset for new level
                    levelStartAt += levelMaxNode;
                    nodeAmountInLevel = 0;
                    currentLevel += 1;
                }
            }

            bfsQueue.pop();
        }

        return output;
    }

    static bool isIdentical(BinaryTree* t1, BinaryTree* t2) {
        return false;
    }

private:

    int _getMaximumDepth(BinaryTreeNode* root) {

        if (root == NULL) {
            return 0;
        }

        int leftDepth = _getMaximumDepth(root->left);
        int rightDepth = _getMaximumDepth(root->right);

        return 1 + max(leftDepth, rightDepth);
    }

    int _getMinimumDepth(BinaryTreeNode* root) {

        if (root == NULL) {
            return 0;
        }

        int leftDepth = _getMinimumDepth(root->left);
        int rightDepth = _getMaximumDepth(root->right);

        return 1 + min(leftDepth, rightDepth);
    }

    BinaryTreeNode* _dfs(BinaryTreeNode* root, int targetValue) {

        if (root == NULL) {
            return NULL;
        }

        // testing
        cout << root->data << ",";

        if (root->data == targetValue) {
            return root;
        }
        else {
            BinaryTreeNode* leftResult = _dfs(root->left, targetValue);
            if (leftResult != NULL) {
                return leftResult;
            }

            BinaryTreeNode* rightResult = _dfs(root->right, targetValue);
            return rightResult;
        }
    }

    void _inorderTraverse(BinaryTreeNode* root, vector<int>& sequence) {

        if (root == NULL) {
            return;
        }

        _inorderTraverse(root->left, sequence);
        sequence.push_back(root->data);
        _inorderTraverse(root->right, sequence);
    }

    void _preorderTraverse(BinaryTreeNode* root, vector<int>& sequence) {

        if (root == NULL) {
            return;
        }

        sequence.push_back(root->data);
        _preorderTraverse(root->left, sequence);
        _preorderTraverse(root->right, sequence);
    }

    void _postorderTraverse(BinaryTreeNode* root, vector<int>& sequence) {

        if (root == NULL) {
            return;
        }

        _preorderTraverse(root->left, sequence);
        _preorderTraverse(root->right, sequence);
        sequence.push_back(root->data);
    }

    void _buildFromPreorderInorder(BinaryTreeNode* parent, bool appendToLeft, 
        vector<int>& preorderSequence, int preorderStartAt, int preorderEndAt, 
        vector<int>& inorderSequence, int inorderStartAt, int inorderEndAt) {

        // idea: deivide & conquer

        // recursion boundry
        if ((preorderEndAt - preorderStartAt) < 0) {
            return;
        }

        int rootValue = preorderSequence[preorderStartAt];

        // find root position in in-order sequence
        int inorderRootPosition;
        for (inorderRootPosition = inorderStartAt; inorderRootPosition <= inorderEndAt; inorderRootPosition++) {
            if (inorderSequence[inorderRootPosition] == rootValue) {
                break;
            }
        }

        BinaryTreeNode* newNode;
        if (parent == NULL) {
            root = new BinaryTreeNode(rootValue);
            newNode = root;
        }
        else {
            newNode = new BinaryTreeNode(rootValue);
            if (appendToLeft) {
                parent->left = newNode;
            }
            else {
                parent->right = newNode;
            }
        }

        int leftSubTreeSize = inorderRootPosition - inorderStartAt;
        int rightSubTreeSize = inorderEndAt - inorderRootPosition;

        // left subtree
        _buildFromPreorderInorder(newNode, true, 
            preorderSequence, preorderStartAt+1, preorderStartAt+leftSubTreeSize, 
            inorderSequence, inorderStartAt, inorderRootPosition-1);

        // right subtree
        _buildFromPreorderInorder(newNode, false, 
            preorderSequence, preorderStartAt+leftSubTreeSize+1, preorderEndAt, 
            inorderSequence, inorderRootPosition+1, inorderEndAt);
        
    }
};

int main() {

    // test BinaryTree constructor 
    vector<int> nodeValues = { 12, 3, 4, 1, 3, 2, -1 };
    BinaryTree* tree = new BinaryTree(nodeValues);
    BinaryTreeNode* root = tree->root;

    cout << (root->right->right == NULL) << endl;
    cout << (root->data == 12) << endl;
    cout << (root->left->data == 3) << endl;

    // test for print
    tree->print();

    delete tree; delete root;

    // test for print
    nodeValues = {12, 3, -1, 4, -1, -1, -1, 5};
    tree = new BinaryTree(nodeValues);
    root = tree->root;
    tree->print();

    delete tree; delete root;

    // test for serlization
    nodeValues = {12, 11, 1, 10, -1, -1, 3};
    tree = new BinaryTree(nodeValues);
    cout << "Original Tree:" << endl;
    tree->print();

    vector<int> sequence = tree->getLevelSequence();

    BinaryTree* clone = new BinaryTree(sequence);
    cout << "Cloned Tree:" << endl;
    clone->print();

    delete tree; delete clone;

    // test for depth
    nodeValues = {12, 1, 4, 5, 22, 2, 3, 16};

    tree = new BinaryTree(nodeValues);
    tree->print();
    cout << "Tree maximum depth: " << tree->getMaximumDepth() << endl;
    cout << "Tree minimum depth: " << tree->getMinimumDepth() << endl;

    cout << "BFS: 2" << endl;
    tree->searchBFS(2);
    cout << endl;

    cout << "DFS: 2" << endl;
    tree->searchDFS(2);
    cout << endl;

    vector<int> inorder = tree->getInorderSequence();
    cout << "In-Order:" << endl;
    for (int i = 0; i < inorder.size(); i++) { cout << inorder[i] << ","; }
    cout << endl;
    vector<int> preorder = tree->getPreorderSequence();
    cout << "Pre-Order:" << endl;
    for (int i = 0; i < preorder.size(); i++) { cout << preorder[i] << ","; }
    cout << endl;
    vector<int> postorder = tree->getPostorderSequence();
    cout << "Post-Order:" << endl;
    for (int i = 0; i < postorder.size(); i++) { cout << postorder[i] << ","; }
    cout << endl;

    clone = new BinaryTree(preorder, inorder);
    cout << "Built from pre-order seq & post-order seq" << endl;
    clone->print();

    delete tree; delete clone;

    return 0;
}