// reference
// https://openhome.cc/Gossip/CppGossip/Lambda.html
// https://docs.microsoft.com/zh-tw/cpp/cpp/lambda-expressions-in-cpp?view=vs-2019

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	string prefix = "vector: ";

	// [] is a capture clause which can capture outer variable by referencing(&) or value-copying(=)
	// [x, y]：access outer variables x, y using '='
	// [x, &y]：access outer var x using '=', access outer var y using '&'
	// [=, &y]：access outer var y using '&', access remained outer variables using '='
	// [&, y]：access var y using '=', access remained outer variables using '='
	auto print = [&prefix](vector<int> list) {
		cout << prefix << "[";
		for (int a : list) {
			cout << a << " ";
		}
		cout << "]" << endl;
	};

	vector<int> list = { -1, 12, -200, 23 };
	print(list);

	sort(list.begin(), list.end(), [](int a, int b) { return a < b; });
	print(list);

	int myAge = 12;

	// Generalized capture
	// In C++14, you can introduce and initialize new variables in the capture clause
	auto getOld = [year = 12](int age) { return age + year; };

	cout << "age: " << getOld(myAge) << endl;

	return 0;
}