// Source : https://leetcode.com/problems/linked-list-cycle/
// Author : CrashedBboy
// Date   : 2020-04-02

// Questions
/********************************************************************************** 
Given a linked list, determine if it has a cycle in it.
To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
 
Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

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
    bool hasCycle(ListNode *head) {

        // utilize 2 pointer to iterate the linked list at different speed respectively
        // if there's a cycle in list, eventually the 2 pointer will point to the same address
        // no matter the length of list is odd or even

        if (head == NULL) {
            return false;
        }

        ListNode *slowRunner = head;
        ListNode *fastRunner = head->next;

        while (slowRunner != fastRunner) {

            if (slowRunner == NULL || fastRunner == NULL) {
                return false;
            }

            slowRunner = slowRunner->next;

            fastRunner = fastRunner->next;

            if (fastRunner == NULL) {

                return false;

            } else {
                
                fastRunner = fastRunner->next;
            }
        }

        return true;

    }
};