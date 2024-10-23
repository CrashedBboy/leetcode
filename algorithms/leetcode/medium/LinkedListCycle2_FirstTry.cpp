#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_map<ListNode*, int> visitCount;

        ListNode* current = head;
        while (current != NULL) {

            visitCount[current] += 1;

            if (visitCount[current] > 1) {
                return current;
            }

            current = current->next;
        }

        return NULL;
    }
};

int main () {

    vector<int> inputs = {3, 2, 0, 4};
    int pos = 1;

    ListNode* head = new ListNode(inputs[0]);
    ListNode* cycleHead = NULL;

    int i = 1;
    ListNode* node = head;
    while (i < inputs.size()) {
        ListNode* newNode = new ListNode(inputs[i]);

        if (i == pos) {
            cycleHead = newNode;
        }

        node->next = newNode;
        node = node->next;
        i += 1;
    }
    node->next = cycleHead;

    Solution sol;
    ListNode* res = sol.detectCycle(head);

    cout << res->val << endl;

    return 0;
}