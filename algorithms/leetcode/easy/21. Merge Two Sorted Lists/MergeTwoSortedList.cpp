#include <iostream>

using namespace std;

struct {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1 == nullptr) { return l2; }
        if (l2 == nullptr) { return l1; }

        ListNode* it1 = l1;
        ListNode* it2 = l2;

        ListNode dummy (0);
        ListNode* merged = &dummy;
        ListNode* it3 = merged;

        while (it1 != nullptr && it2 != nullptr) {

            if (it1->val <= it2->val) {
                it3->next = it1;
                it1 = it1->next;
            }
            else {
                it3->next = it2;
                it2 = it2->next;
            }

            it3 = it3->next;
        }

        it3->next = (it1 == nullptr)? it2 : it1;

        return merged->next;
    }
};