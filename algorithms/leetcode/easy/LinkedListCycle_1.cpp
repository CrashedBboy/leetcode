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

private:
    // use a hash table which utilize addr of ListNode as key,
    // map[addr] = 1 indicates that the node has been pointed
    std::map<ListNode*, int> visited;

public:
    bool hasCycle(ListNode *head) {

        if (head == NULL) {

            // iterating reachs end of list and recursion didn't report(return) any cycle
            return false;
        }

        if (visited.count(head) > 0) {

            return true;
        }

        visited[head] = 1;

        return hasCycle(head->next);
    }
};