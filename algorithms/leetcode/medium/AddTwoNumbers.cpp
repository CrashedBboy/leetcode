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

#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // get lengths of the two
        int length1 = 0, length2 = 0;
        ListNode* tmp = l1;
        while (tmp != NULL) { length1 += 1; }
        tmp = l2;
        while (tmp != NULL) { length2 += 1; }

        // store sum results on larger list
        ListNode* longer; ListNode* longerHead;
        ListNode* shorter; ListNode* shorterHead;

        if (length1 >= length2) { longerHead = longer = l1; shorterHead = shorter = l2; }
        else { longerHead = longer = l2; shorterHead = shorter = l1; }

        int val1, val2, carry = 0;
        while (longer != NULL) {
            val1 = longer->val;
            val2 = (shorter == NULL)? 0 : shorter->val;

            int digitSum = val1 + val2 + carry;
            longer->val = digitSum % 10;
            carry = (int)(digitSum / 10);

            longer = longer->next;
            if (shorter != NULL) { shorter = shorter->next; }
        }

        // return head of larger list
        return longerHead;
    }
};


int main () {

    vector<int> nums1 = {9,9,9,9,9,9,9};
    vector<int> nums2 = {9,9,9,9};

    ListNode* head1 = new ListNode(nums1[0]);
    ListNode* tmp = head1;
    for (int i = 1; i < nums1.size(); i++) {
        ListNode* newNode = new ListNode(nums1[i]);
        tmp->next = newNode;
        tmp = tmp->next;
    }
    
    ListNode* head2 = new ListNode(nums2[0]);
    tmp = head2;
    for (int i = 1; i < nums2.size(); i++) {
        ListNode* newNode = new ListNode(nums2[i]);
        tmp->next = newNode;
        tmp = tmp->next;
    }

    Solution sol;
    ListNode* sum = sol.addTwoNumbers(head1, head2);
    tmp = sum;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;


    return 0;
}