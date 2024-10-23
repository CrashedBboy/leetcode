/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {

        node->val = node->next->val;
        node->next = node->next->next;
    }
};


int main() {

    vector<int> nums = { 4, 5, 1, 9 };
    ListNode* head = new ListNode(nums[0]);

    ListNode* current = head;
    for (int i = 1; i < nums.size(); i++) {
        ListNode* n = new ListNode(nums[i]);
        current->next = n;
        current = n;
    }

    Solution s;
    s.deleteNode(head->next);

    // print
    current = head;
    while (current != NULL) {
        cout << current->val << ",";
        current = current->next;
    }
    cout << endl;

    return 0;
}