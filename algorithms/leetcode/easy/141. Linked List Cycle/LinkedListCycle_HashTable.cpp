#include <unordered_map>

using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {

        unordered_map<ListNode*, bool> map; // address: visited

        ListNode* it = head;
        while (it != nullptr) {
            if (map[it]) {
                return true;
            }
            else {
                map[it] = true;
                it = it->next;
            }
        }

        return false;
    }
};