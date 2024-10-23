#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {

        if (head == nullptr) return false;
        
        ListNode* walker = head;
        ListNode* runner = head;

        while (runner->next != nullptr && runner->next->next != nullptr ) {

            runner = runner->next->next;
            walker = walker->next;

            if (runner == walker) {
                return true;
            }
        }

        return false;
    }
};