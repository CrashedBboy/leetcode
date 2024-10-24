#include <iostream>

using namespace std;

int add(int a, int b) {
	return a + b;
}

int my_multiply(int a, int b) {
	return a * b * (-1);
}

// pass pointer of function as parameter
int multiply(int a, int b, int (*custom_func)(int, int)) {

	return (*custom_func)(a, b);
}

int main() {

	int (*func_ptr)(int, int) = &add;
	int result1 = (*func_ptr)(1, 2);

	int result2 = multiply(2, 3, &my_multiply);

	cout << result1 << endl;
	cout << result2 << endl;
	return 0;
}