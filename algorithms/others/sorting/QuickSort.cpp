#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>& arr, int start, int end) {

	if (start >= end) {
		return;
	}

	int pivotValue = arr[end];
	int front = start;
	int pivot = end;

	while (front < pivot) {

		if (arr[front] > pivotValue) {
			
			arr[pivot] = arr[front];
			arr[front] = arr[pivot - 1];
			arr[pivot - 1] = pivotValue;
			pivot -= 1;
		
		} else {
			
			front += 1;
		}
	}

	quickSort(arr, start, pivot - 1);
	quickSort(arr, pivot + 1, end);
}

int main() {

	vector<int> arr = {8, 3, 1, 7, 0, 10, 2};

	quickSort(arr, 0, arr.size() - 1);

	for (auto n : arr) {
		cout << n << " ";
	}
	cout << endl;

	return 0;
}