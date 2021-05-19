using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // [idae]
        // use two iterator to go through the list at the same speed
        // if iterator A reach the end, redirect to list B to continue
        // similarly, if iterator B reach the end, redirect it to list A to continue

        // by switching the iterating list, they will eventually have the same amount node to go through
        // so once the two iterator meet each other, the node will be the intersection

        // if the lists are not intersected? both redirected iterator will reach NULL again
        
        ListNode* itA = headA;
        ListNode* itB = headB;
        bool switched = false;

        while (true) {

            if (itA == itB) return itA;

            if (itA->next == nullptr && itB->next == nullptr) {
                return nullptr;
            }
            else if (itA->next == nullptr) {
                itA = headB;
                itB = itB->next;
            }
            else if (itB->next == nullptr) {
                itB = headA;
                itA = itA->next;
            }
            else {
                itB = itB->next;
                itA = itA->next;
            }
        }

        return nullptr;
    }
};