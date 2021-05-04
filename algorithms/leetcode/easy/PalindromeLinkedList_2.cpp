// Source : https://leetcode.com/problems/palindrome-linked-list/
// Author : CrashedBboy
// Date   : 2020-04-03

// Questions
/********************************************************************************** 
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

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
    bool isPalindrome(ListNode* head) {

        // example: 
        // 1 1 2 3 4 5 5 4 3 2 2 3 4 5 5 4 3 2 1 1

        // [idea 2]
        // iterate the list to get the total length
        // then reverse the front half linked list
        // at the middle of list, use 2 pointers to iterate to head and to end respectively, move one step at a time
        // in every iterating step, check if the two iterated node have the same value

        if (head == NULL) {
            return true;
        }

        int listLength = 0;

        ListNode *iteratorA = head;

        while (iteratorA != NULL) {

            listLength += 1;

            iteratorA = iteratorA->next;
        }

        // start to reverse the front half of the linked list

        // reversing stops at which position(/index)?
        //// if length is even: reverse to N/2 - 1 
        //// if length is odd: (N-1)/2 - 1

        ListNode *iteratorB;
        
        int reverseStopAt = listLength%2 == 0? listLength/2 - 1 : (listLength-1)/2 - 1;

        iteratorA = head;
        ListNode *previousNode = NULL;
        for (int i = 0; i <= reverseStopAt; i++) {

            ListNode *nextNode = iteratorA->next;
            iteratorA->next = previousNode;
            previousNode = iteratorA;

            if (i != reverseStopAt) {

                iteratorA = nextNode; // stop go further!

            } else {

                iteratorB = listLength%2 == 0? nextNode : nextNode->next;
            }
        }

        // two pointer go in opposite direction and check if the values are the same (or not)
        while (iteratorA != NULL && iteratorB != NULL) {

            if (iteratorA->val != iteratorB->val) {
                return false;
            }

            iteratorA = iteratorA->next;
            iteratorB = iteratorB->next;
        }

        return true;
    }
};