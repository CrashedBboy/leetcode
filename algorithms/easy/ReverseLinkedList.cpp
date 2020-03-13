// Source : https://leetcode.com/problems/reverse-linked-list
// Author : CrashedBboy
// Date   : 2020-03-12

// Questions
/********************************************************************************** 

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

**********************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) { return head; }

        ListNode *previousNode = NULL;
        ListNode *iteratedNode = head;
        ListNode *tempNode;

        while (true){

            tempNode = iteratedNode->next;

            iteratedNode->next = previousNode;

            previousNode = iteratedNode;

            if (tempNode == NULL) {
                return iteratedNode;
            } else {
                iteratedNode = tempNode;
            }
        }
    }
};