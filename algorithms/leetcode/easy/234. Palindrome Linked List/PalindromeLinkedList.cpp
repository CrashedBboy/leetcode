
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// [idea]
// Phase 1: Reverse the first half while finding the middle.
// Phase 2: Compare the reversed first half with the second half.

// [other idea]
// use stack to store all values and pop all (to be reversed sequence)

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return true;
        } 

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;

            ListNode* tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        
        ListNode* it1;
        ListNode* it2;
        if (fast == nullptr) {
            it1 = prev; it2 = slow;
        }
        else {
            it1 = prev; it2 = slow->next;
        }

        while (it1 != nullptr && it2 != nullptr) {
            if (it1->val != it2->val) {
                return false;
            }

            it1 = it1->next; it2 = it2->next;
        }

        return true;
    }
};