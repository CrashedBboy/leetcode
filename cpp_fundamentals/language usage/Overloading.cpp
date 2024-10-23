#include <iostream>

using namespace std;

class Box {

public:
	Box(int len = 0) :length(len) { }

	Box operator+ (Box& b) {
		Box newBox;

		newBox.length = length + b.length;
		return newBox;
	}

	Box operator+ (int newLength) {
		Box newBox;

		newBox.length = length + newLength;
		return newBox;
	}

	void print() {
		cout << "Box length: " << length << endl;
	}

private:
	int length;
};


int main() {

	Box b1(12);
	Box b2(3);

	Box b3 = b1 + b2;
	b3.print();

	Box b4 = b1 + 4;
	b4.print();

	return 0;
}