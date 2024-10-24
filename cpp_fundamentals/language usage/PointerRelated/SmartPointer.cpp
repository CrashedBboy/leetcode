#include <memory>
#include <iostream>

using namespace std;


int main (void) {

	size_t	length = 10;

	unique_ptr<int[]> data = make_unique<int[]>(length);

	for (int i = 0; i < length; i++) {
		data[i] = i*2;
	}

	for (int i = 0; i < length; i++) {
		cout << data[i] << ",";
	}
	cout << endl;




	shared_ptr<int> sharedData = make_shared<int>();
	shared_ptr<int> guest = sharedData;
	*sharedData = 3;
	cout << *guest << endl;

	return 0;
}
