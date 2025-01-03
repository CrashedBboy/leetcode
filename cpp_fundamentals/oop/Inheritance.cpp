#include <iostream>


using namespace std;

class Base {
public:
    Base() {
        cout << "Base constructor" << endl;
    }
    ~Base() {
        cout << "Base destructor" << endl;
    }
};

class Derived : Base {
public:
    Derived() {
        cout << "Derived constructor" << endl;
    }
    ~Derived() {
        cout << "Derived destructor" << endl;
    }
};

int main(void) {

    Derived d;

    return 0;
}

/*
Order of construction and destruction:
    Base constructor
    Derived constructor
    Derived destructor
    Base destructor
*/