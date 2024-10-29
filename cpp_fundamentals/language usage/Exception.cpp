/*

Reason of using exceptions:
1. seperating error handling code from the program main logic
2. group error types

*/

#include <iostream>
#include <stdexcept>

using namespace std;

float example1(float numerator, float denominator) {
    try {
        if (denominator == 0) {
            throw runtime_error("divide-by-zero!");
        }
        return (numerator/denominator);
    }
    catch (...) { // catch all types of exception
        throw; // throw to caller to handle that
    }
}

class Object {
public:
    Object(int i): id(i) { cout << "object " << this->id <<" is created" << endl; }
    ~Object() { cout << "object " << this->id <<" is destructed" << endl; }
private:
    int id;
};
void example2() {
    try {
        Object o1(1);
        Object o2(2);
        throw "exception can be any type";
        Object o3(3); // will not have the chance to be executed
    }
    catch (...) {
        cout << "exception is caught" << endl;
    }
    // Stack unwinding: all objects declared in the try block are destructed before the exception is caught
    // expected output:
        // object 1 is created
        // object 2 is created
        // object 2 is destructed
        // object 1 is destructed
        // exception is caught
}

class Base {};
class Derived: public Base {};
void example3() {
    try {
        Derived d1;
        throw d1;
    }
    catch (Base b) {
        cout << "Caught Base object" << endl;
    }
    catch (Derived d) {
        cout << "Caught Derived object" << endl;
    }
    catch (...) {

    }
    // expected output:
    // (first matching catch block is executed!)
    // "Caught Base object""
}

int main(void) {

    try {
        cout << example1(12, 0) << endl;
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    example2(); // this function's exception is handled by itself

    example3(); // demonstrates the importance of caught type orders
     
}