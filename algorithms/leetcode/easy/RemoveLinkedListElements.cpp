// Source : https://leetcode.com/problems/remove-linked-list-elements/
// Author : CrashedBboy
// Date   : 2020-12-06

// Questions
/********************************************************************************** 
Remove all elements from a linked list of integers that have value `val`.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
**********************************************************************************/

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
class Solution {

public:
    ListNode* removeElements(ListNode* head, int val) {

        // if (head == NULL) { return NULL; }

        ListNode* prev = NULL;
        ListNode* current = head;

        while (current != NULL) {

            if (current->val == val) {
                if (prev != NULL) { prev->next = current->next; }

                // if matched is head, head pointer need to move
                if (current == head) {
                    head = current->next;
                }

                // don't need to move prev
                current = current->next;
            } else {
                prev = current;
                current = current->next;
            }
        }
        
        return head;
    }
};