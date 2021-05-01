// construct min-heap with input {1, 6, 4, -2, -9}

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main() {

	vector<int> inputs = { 1, 6, 4, -2, -9 };

	// comp function
	auto desc = [](int a, int b) { return a > b; };

	priority_queue<int, vector<int>, decltype(desc)> minHeap(desc);

	// append values and heapify
	for (int i = 0; i < inputs.size(); i++) {
		minHeap.push(inputs[i]);
	}

	// iterately pop top node
	while (!minHeap.empty()) {
		int smallest = minHeap.top();
		cout << smallest << ", ";
		minHeap.pop();
	}
	cout << endl;

	return 0;
}

// NOTE!! DESC (less) comp function --> the top of heap is the smallest!