#include <iostream>
#include <string>

using namespace std;

class Human {

public:
	virtual void say() {
		cout << "I'm a human." << endl;
	}
};

class Man : public Human {

public:
	void say() {
		cout << "I'm a man." << endl;
	}
};

class Woman : public Human {

public:
	void say() {
		cout << "I'm a woman" << endl;
	}
};

void introduce(Human& h) {
	h.say();
}


int main() {

	Human h;
	Man m;
	Woman w;

	introduce(h); // with 'virtual' function, it shoule output 'human'
	introduce(m); // with 'virtual' function, it shoule output 'man'
	introduce(w); // with 'virtual' function, it shoule output 'woman'

	return 0;
}