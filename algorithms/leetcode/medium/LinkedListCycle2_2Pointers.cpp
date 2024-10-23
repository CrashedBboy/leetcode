#include <iostream>
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

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != NULL && slow != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
            }
            else {
                return NULL;
            }

            slow = slow->next;

            // fast meets slow: cycle exists
            if (fast == slow && fast != NULL) {
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }

                return fast;
            }
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