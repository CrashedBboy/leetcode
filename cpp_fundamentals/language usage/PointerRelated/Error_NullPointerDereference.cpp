
#include <iostream>
#include <memory>

using namespace std;

void problem(int* a) {
    cout << "Value of a: " << *a << endl;
}

void solution1(int* a) {
    // check if pointer is null before dereferencing it
    if (a != nullptr) {
        cout << "Value of a: " << *a << endl;
    }
    else {
        cout << "warning: null pointer" << endl;
    }
}

// pass by value is ok for shared_ptr
void solution2(shared_ptr<int> a) {
    if (a != nullptr) {
        cout << "Value of a: " << *a << endl;
    }
}

// should pass by ref if it is unique_ptr 
void solution3(unique_ptr<int>& a) {
    if (a != nullptr) {
        cout << "Value of a: " << *a << endl;
    }
}

int main(void) {
    int* a = nullptr;

    // problem(a);
    solution1(a);

    // HOW TO PREVENT: use smart pointer
    // if passing unique_ptr, make sure you are passing by reference instead of pass by value
    // otherwise the new unique_ptr will be created by its constructor is set to deleted => error!
    // if passing shared_ptr, such class's constructor is not set to be deleted, can either be passed by ref or value
    shared_ptr<int> ap = make_shared<int>( /* if no int value (the value to be new and pointed), by default it will be 0 */ );
    solution2(ap);

    unique_ptr<int> ap2 (nullptr);
    // unique_ptr<int> ap2 = make_unique<int>();
    solution3(ap2);

    return 0;
}