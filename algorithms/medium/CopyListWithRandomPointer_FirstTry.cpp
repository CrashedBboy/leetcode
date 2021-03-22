#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL) {
            return NULL;
        }
        
        // build data strucuture to represent pointing map
        unordered_map<Node*, int> nodeIdx; // <address, index>
        Node* tmp = head; int idx = 0;
        while (tmp != NULL) {
            nodeIdx[tmp] = idx;
            tmp = tmp->next;
            idx += 1;
        }

        vector<int> randomPointTo;
        tmp = head;
        while (tmp != NULL) {
            if (tmp->random == NULL) {
                randomPointTo.push_back(-1);
            }
            else {
                randomPointTo.push_back(nodeIdx[tmp->random]);
            }
            tmp = tmp->next;
        }

        // now create new linked list from built pointing map
        unordered_map<int, Node*> idxNode; // <idx, address>

        Node* newHead = NULL;
        Node* newTmp = newHead;
        tmp = head; idx = 0;
        while (tmp != NULL) {

            Node* newNode = new Node(tmp->val);

            if (newHead == NULL) {
                newTmp = newHead = newNode;
            }

            idxNode[idx] = newNode;

            newTmp->next = newNode;
            newTmp = newNode;
            tmp = tmp->next;
            idx += 1;
        }

        // connect the random pointer
        newTmp = newHead;
        for (int i = 0; i < randomPointTo.size(); i++) {

            if (randomPointTo[i] != -1) {
                newTmp->random = idxNode[randomPointTo[i]];
            }

            newTmp = newTmp->next;
        }

        cout << newHead->val << endl;

        return newHead;
    }
};