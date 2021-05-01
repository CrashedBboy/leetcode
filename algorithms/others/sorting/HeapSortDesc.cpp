// construct max-heap with input {1, 6, 4, -2, -9}

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main() {

	vector<int> inputs = { 1, 6, 4, -2, -9 };

	// comp function
	auto asc = [](int a, int b) { return a < b; };
	priority_queue<int, vector<int>, decltype(asc)> maxHeap (asc); // priority_queue<element type, container type, compare function type>

	for (int i = 0; i < inputs.size(); i++) {
		maxHeap.push(inputs[i]);
	}

	while (!maxHeap.empty()) {
		int greatest = maxHeap.top();
		cout << greatest << ", ";
		maxHeap.pop();
	}
	cout << endl;

	return 0;
}

// NOTE!! ACS (greater) comp function --> the top of heap is the greatest!