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

#include <iostream>

using namespace std;


struct ListNode {

    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = nullptr;
        ListNode* node = head;

        while (node != nullptr) {

            ListNode* tmp = node->next;
            node->next = prev;

            prev = node;
            node = tmp;
        }

        return prev;
    }
};

int main () {

    ListNode* head = new ListNode(12);

    head->next = new ListNode(21);

    head->next->next = new ListNode(33);

    Solution sol;

    ListNode* newHead = sol.reverseList(head);

    ListNode* current = newHead;
    while (current != nullptr) {
        cout << current->val << ",";

        current = current->next;
    }
    cout << endl;


    return 0;
}