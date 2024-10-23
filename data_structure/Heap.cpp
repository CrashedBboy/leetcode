// [concept]
// index of left child: i*2 + 1, index of right child: i*2 + 2
// index of parent: (int)(i-1)/2
// pop top: -> put the last element to top -> iteratively swap with the largest child from top to bottom (Top-down)
// push: -> insert at the back of array, iteratively compare with its parent (Bottom-up)

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {

    vector<int> inputs = {20, 42, -12, 3, 33, 11};

    vector<int> maxHeap = {};

    // insert & heapify
    for (int i = 0; i < inputs.size(); i++) {
        maxHeap.push_back();
        int index = maxHeap.size() - 1;
        int parentIndex = (index - 1) / 2;

        while (parentIndex >= 0) {
            if (maxHeap[parentIndex] < maxHeap[index]) {
                swap(maxHeap[parentIndex], maxHeap[index]);
                index = parentIndex;
                parentIndex = (index - 1) / 2;
            }
            else {
                break; // stop bottom-up
            }
        }
    }

    // heap-sort
    vector<int> outputs = {};

    while (!maxHeap.empty()) {
        outputs.push_back(maxHeap[0]);
        
        // remove top & move the last item to be new top
        maxHeap[0] = maxHeap.back();
        maxHeap.pop_back();

        // heapify
        int index = 0;
        int leftChildIndex = index * 2 + 1;
        int rightChildIndex = index * 2 + 2;
        while (leftChildIndex < maxHeap.size()) {

            // if right child is not NULL
            if (rightChildIndex < maxHeap.size()) {

                if ( max(max(maxHeap[rightChildIndex], maxHeap[leftChildIndex]), maxHeap[index]) == maxHeap[rightChildIndex]) {
                    swap(maxHeap[rightChildIndex], maxHeap[index]);
                    index = rightChildIndex;
                    leftChildIndex = index * 2 + 1;
                    rightChildIndex = index * 2 + 2;
                }
                else if ( max(max(maxHeap[rightChildIndex], maxHeap[leftChildIndex]), maxHeap[index]) == maxHeap[leftChildIndex] ) {
                    swap(maxHeap[leftChildIndex], maxHeap[index]);
                    index = leftChildIndex;
                    leftChildIndex = index * 2 + 1;
                    rightChildIndex = index * 2 + 2;
                }
                else {
                    // current node is the biggest in the subtree
                    break;
                }
            }
            else {

                if ( max(maxHeap[leftChildIndex], maxHeap[index]) == maxHeap[leftChildIndex] ) {
                    swap(maxHeap[leftChildIndex], maxHeap[index]);
                    index = leftChildIndex;
                    leftChildIndex = index * 2 + 1;
                    rightChildIndex = index * 2 + 2;
                }
                else {
                    // current node is the biggest in the subtree
                    break;
                }
            }
        }
    }

    cout << "Sorted:" << endl;
    for (auto& a : outputs) {
        cout << a << ",";
    }
    cout << endl;

    return 0;
}