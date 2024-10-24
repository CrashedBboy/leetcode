#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	unsigned int x = 0xa;

	void* ptr = (void*)&x;
	*(unsigned int*)ptr = 5;

	cout << x << endl;

	void* arr = malloc(sizeof(int) * 10);

	*(int*)(arr) = 0x12345678;

	printf("%x \n", *(char*)(arr)); // 0x78 (little endian)

	free(arr);

	return 0;
}