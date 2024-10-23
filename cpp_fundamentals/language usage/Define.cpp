#include <iostream>

using namespace std;

#define ADD_TWO(x,y) x+=2;y+=2;

int main() {

	bool flag = false;
	int j = 5, k = 7;
	if (flag) ADD_TWO(j, k);

	cout << j << endl; // would be 5
	cout << k << endl; // would be 9

	return 0;
}