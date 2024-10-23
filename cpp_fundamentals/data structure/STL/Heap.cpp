// reference: http://www.cplusplus.com/reference/queue/priority_queue/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	vector<int> numbers = {1, 6, 4, -2, -9};

	// [Max Heap 1]

	auto ascCmp = [](int a, int b) { return a < b; }; // lambda function

	priority_queue<int, vector<int>, decltype(ascCmp)> maxHeap(ascCmp); // decltype(): used with 'auto', infer and generate the corresponding type 

	for (int n : numbers) { 
		maxHeap.push(n); // push and heapify: O(logN)
	}

	while (!maxHeap.empty()) {
		cout << maxHeap.top() << " "; // get top of heap
		maxHeap.pop(); // pop top: O(logN)
	}
	cout << endl;

	// [Min Heap]

	auto descCmp = [](int a, int b) { return a > b; };  // lambda function
	
	priority_queue<int, vector<int>, decltype(descCmp)> minHeap(numbers.begin(), numbers.end(), descCmp);

	while (!minHeap.empty()) {
	
		cout << minHeap.top() << " ";
		minHeap.pop();
	}
	cout << endl;

	return 0;
}

// use priority_queue:
// <queue>
// top(), pop(), push(), size(), empty()