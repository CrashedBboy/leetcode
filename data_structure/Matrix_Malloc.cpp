#include <iostream>

using namespace std;

int main() {

	const int width = 3;
	const int height = 2;

	// create
	int **matrix = (int**) malloc(sizeof(int*) * height);

	for (int i = 0; i < height; i++) {
		*(matrix + i) = (int*)malloc(sizeof(int) * width);
	}

	// access
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			*(*(matrix + i) + j) = 0;
			cout << *(*(matrix + i) + j) << " ";
		}
		cout << endl;
	}

	return 0;
}