#include <iostream>
#include <memory>

using namespace std;

void problem() {

    int* ptr = new int(5);

    delete ptr;

    // the ptr still point to the same address,
    // but the data on that address is longer under ptr's control
    cout << *ptr << endl; // unexpected/undefined result
}

void solution1() {
    // good practice: always set the pointer to nullptr when delete it.
    int* ptr = new int(5);

    delete ptr; ptr = nullptr;

    // check the pointer when deferencing it
    if (ptr != nullptr) {
        cout << *ptr << endl;
    }
}

void solution2() {
    // alternative: if smart pointer is used, we still need to do pointer check when deferencing
    unique_ptr<int> ptr = make_unique<int>(5);

    // Free the memory before we exit function block.
    ptr.reset(); 

    // pointer check
    if (ptr != nullptr) {
        cout << *ptr << endl;
    }
}

int main(void) {

    // problem();
    solution1();
    // solution2();

    return 0;
}