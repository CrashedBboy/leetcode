/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// idea: reversed order -> using stack

#include <stack>
#include <iostream>
#include <vector>

using namespace std;

class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // create stack to store address of nodes
        stack<ListNode*> visitedNodes;
        
        // starting traversing
        ListNode* current = head;
        while (current != NULL) {
            visitedNodes.push(current);
            current = current->next;
        }
        
        // pop n times to get the address of target node
        ListNode* target;
        for (int i = 0; i < n; i++) {
            target = visitedNodes.top();
            visitedNodes.pop();
        }
        
        // start removing it
        if (target != head) {
            // pop 1 time again to get the previous node of the target
            ListNode* targetPrev = visitedNodes.top();
            targetPrev->next = target->next;
        }
        else {
            // our target is the head of linked list
            // need to update head
            head = target->next;
        }
        
        return head;
    }
};

// using 2 pointers, they have distance of n between each other

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if (head == NULL) {
            return head;
        }
        
        ListNode* front = head;
        ListNode* back = head;
        
        for (int i = 1; i < n; i++) {
            
            // check
            if (back == NULL) {
                return head;
            }
            back = back->next;
        }
        
        ListNode* frontPrev = NULL;
        while (back->next != NULL) {
            frontPrev = front;
            front = front->next;
            back = back->next;
        }
        
        if (frontPrev != NULL) {
            frontPrev->next = front->next;
        }
        else {
            head = front->next;
        }
        
        return head;
        
    }
};