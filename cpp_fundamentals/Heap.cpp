#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	vector<int> numbers = {1, 6, 4, -2, -9};

	// [Max Heap]

	auto ascCmp = [](int a, int b) { return a < b; };
	priority_queue<int, vector<int>, decltype(ascCmp)> maxHeap(ascCmp);

	for (int n : numbers) { 
		maxHeap.push(n); // push and heapify: O(logN)
	}

	while (!maxHeap.empty()) {
		cout << maxHeap.top() << " "; // get top of heap
		maxHeap.pop(); // pop top: O(logN)
	}
	cout << endl;

	// [Min Heap]

	auto descCmp = [](int a, int b) { return a > b; };
	priority_queue<int, vector<int>, decltype(descCmp)> minHeap(descCmp);

	for (int n : numbers) {
		minHeap.push(n);
	}

	while (!minHeap.empty()) {
	
		cout << minHeap.top() << " ";
		minHeap.pop();
	}
	cout << endl;

	return 0;
}