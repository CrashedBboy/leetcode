#include <iostream>

using namespace std;

int add(int a, int b) {
	return a + b;
}

int main() {

	int (*func_ptr)(int, int) = &add;

	int result = (*func_ptr)(1, 2);

	cout << result << endl;

	return 0;
}