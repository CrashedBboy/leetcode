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

        unordered_map<Node*, Node*> mappingOldNew; // <old node addr, new node addr>

        Node* tmp = head;
        while (tmp != NULL) {
            Node* newNode = new Node(tmp->val);
            mappingOldNew[tmp] = newNode;

            tmp = tmp->next;
        }

        tmp = head;
        while (tmp != NULL) {
            Node* theNew = mappingOldNew[tmp];
            theNew->next = mappingOldNew[tmp->next];
            theNew->random = mappingOldNew[tmp->random];

            tmp = tmp->next;
        }

        return mappingOldNew[head];
    }
};