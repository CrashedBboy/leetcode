#include <stdlib.h>
#include <stdio.h>

#define ROW_N 4
#define COL_N 3

using namespace std;

int main() {

	int** matrix = (int**)malloc(sizeof(int*) * ROW_N);
	// malloc() return (void*)
	// we need to cast the void* pointer to int* pointer

	for (int i = 0; i < ROW_N; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * COL_N);
	}

	for (int r = 0; r < ROW_N; r++) {
		for (int c = 0; c < COL_N; c++) {
			matrix[r][c] = (r + c);
			printf("%d ", matrix[r][c]);
		}
		printf("\n");
	}

	free(matrix);

	return 0;
}