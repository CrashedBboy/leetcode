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

private:
    stack<int> values;
public:
    bool isPalindrome(ListNode* head) {
        
        // [idea 1]
        // use stack to store visited values
        // then iterate the list from head again, and pop the stack at the same time
        // check if the popped value is equal to iterated node or not

        // example: 
        // 1 1 2 3 4 5 5 4 3 2 2 3 4 5 5 4 3 2 1 1

        if (head == NULL) {
            return true;
        }

        ListNode *iterator = head;

        while (iterator != NULL) {

            values.push(iterator->val);

            iterator = iterator->next;
        }

        iterator = head;

        while (iterator != NULL) {

            if (values.top() != iterator->val) {
                return false;
            }

            iterator = iterator->next;
            values.pop();
        }

        return true;

    }
};