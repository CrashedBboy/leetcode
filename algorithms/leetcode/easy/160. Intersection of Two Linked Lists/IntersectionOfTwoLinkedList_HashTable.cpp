#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_map<ListNode*, bool> visited;

        ListNode* it = headA;
        while (it != nullptr) {
            visited[it] = true;
            it = it->next;
        }

        it = headB;
        while (it != nullptr) {
            if (visited[it] == true) {
                return it;
            }
            it = it->next;
        }

        return nullptr;
    }
};