#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int>& arr, int start, int end) {

	if (start == end) {
		return;
	}

	// divide
	int center = (start + end) / 2;
	mergeSort(arr, start, center);
	mergeSort(arr, center + 1, end);

	// conquer (merge)
	int i = start;
	int j = center + 1;

	vector<int> merged;
	while (i <= center && j <= end) {
		
		if (arr[i] <= arr[j]) {
			merged.push_back(arr[i]);
			i += 1;
		
		} else {
		
			merged.push_back(arr[j]);
			j += 1;
		}
	}

	while (i <= center) {
		merged.push_back(arr[i]);
		i += 1;
	}

	while (j <= end) {
		merged.push_back(arr[j]);
		j += 1;
	}

	for (int i = 0; i < merged.size(); i++) {
		arr[start + i] = merged[i];
	}
}

int main() {

	vector<int> arr = {8, 3, 1, 7, 0, 10, 2};

	mergeSort(arr, 0, arr.size() - 1);

	for (auto n : arr) {
		cout << n << " ";
	}
	cout << endl;

	return 0;
}