// Source : https://leetcode.com/problems/merge-two-sorted-lists/
// Author : CrashedBboy
// Date   : 2020-03-28

// Questions
/********************************************************************************** 

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        // check the input
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }
        
        if (l1 == NULL) {
            return l2;
        }
        
        if (l2 == NULL) {
            return l1;
        }

        // iterator for list1 and list2
        ListNode *it1 = l1;
        ListNode *it2 = l2;

        ListNode *returnList;
        ListNode *returnListLast; // iterator of list to be returned
        bool started = false;

        while (it1 != NULL && it2 != NULL) {

            ListNode *newNode;
            if (it1->val <= it2->val) {
                newNode = new ListNode(it1->val);
                it1 = it1->next;
            } else {
                newNode = new ListNode(it2->val);
                it2 = it2->next;
            }

            // if there's no node in the list to be returned
            if (started == false) {
                started = true;
                returnList = newNode;
                returnListLast = returnList;
            } else {

                // append new node into return-list
                returnListLast->next = newNode;

                // update the iterator
                returnListLast = newNode;
            }
        }

        // push the remains of input list into return-list
        if (it1 == NULL) {
            while (it2 != NULL) {
                ListNode *newNode = new ListNode(it2->val);
                returnListLast->next = newNode;
                returnListLast = newNode;
                it2 = it2->next;
            }
        }

        if (it2 == NULL) {
            while (it1 != NULL) {
                ListNode *newNode = new ListNode(it1->val);
                returnListLast->next = newNode;
                returnListLast = newNode;
                it1 = it1->next;
            }
        }

        return returnList;
    }
};
