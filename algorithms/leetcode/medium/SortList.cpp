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

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {

        if (head == NULL) {
            return head;
        }
        
        int nodeCount = 0;
        ListNode* current = head;
        while (current != NULL) {
            nodeCount += 1;
            current = current->next;
        }
        
        ListNode* sorted = mergeSort(head, nodeCount);

        // make tail->next points to NULL
        int count = 1;
        ListNode* tail = sorted;
        while (count < nodeCount) {
            tail = tail->next;
            count += 1;
        }
        tail->next = NULL;

        return sorted;
    }

private:
    ListNode* mergeSort(ListNode* head, int nodeCount) {
        if (nodeCount == 1) {
            return head;
        }

        ListNode* rightHead = head;
        int leftNodeCount = 1;
        int leftSequenceLength = (int) (nodeCount/2);
        while (leftNodeCount <= (int)(nodeCount/2)) {
            rightHead = rightHead->next;
            leftNodeCount += 1;
        }

        // divide
        ListNode* leftSorted = mergeSort(head, leftSequenceLength);
        ListNode* rightSorted = mergeSort(rightHead, (nodeCount - leftSequenceLength));

        if (leftSorted == NULL) {
            return rightSorted;
        }
        else if (rightSorted == NULL) {
            return leftSorted;
        }

        // merge
        ListNode* leftCurrent = leftSorted;
        ListNode* rightCurrent = rightSorted;
        int leftIndex = 1, rightIndex = 1;
        ListNode* leftPrev = NULL;
        while (leftIndex <= leftSequenceLength && rightIndex <= (nodeCount - leftSequenceLength)) {

            while ((leftCurrent->val <= rightCurrent->val) && (leftIndex <= leftSequenceLength)) {
                leftIndex += 1;
                leftPrev = leftCurrent;
                leftCurrent = leftCurrent->next;
            }

            if (leftIndex <= leftSequenceLength) {
                // now leftCurrent is greater than rightCurrent
                // insert rightCurrent into left list (insert before the leftCurrent)
                ListNode* tmp = rightCurrent->next;
                if (leftPrev!= NULL) {
                    leftPrev->next = rightCurrent;
                }
                rightCurrent->next = leftCurrent;
                leftPrev = rightCurrent;

                rightCurrent = tmp;
                rightIndex += 1;
            }
            else {
                // append all the remained right nodes after left list
                leftPrev->next = rightCurrent;
            }
        }

        if (leftSorted->val <= rightSorted->val) {
            return leftSorted;
        }
        else {
            return rightSorted;
        }
    }
};

int main () {

    // vector<int> inputs = {-1, 5, 3, 4, 0};
    vector<int> inputs = {4, 2, 1, 3};

    ListNode* head = new ListNode(inputs[0]);

    ListNode* current = head;
    for (int i = 1; i < inputs.size(); i++) {
        ListNode* node = new ListNode(inputs[i]);
        current->next = node;
        current = node;
    }

    Solution sol;
    ListNode* sorted = sol.sortList(head);

    current = sorted;
    while (current != NULL) {
        cout << current->val << ",";
        current = current->next;
    }
    cout << endl;

    return 0;
}