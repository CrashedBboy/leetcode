#include <iostream>

using namespace std;

void problem() {
    int* ptr; // create a pointer without assign a valid address, it might point to anywhere!
    // if it point to random or garbage memory, leading to crashes or corrupted data.

    cout << *ptr << endl; // what the value it might be is unpredictable
    *ptr = 10; // where on the memory is this '10' written to ??
    cout << *ptr << endl;
}

void solution() {
    // alwasy initialize the pointer
    int* ptr = nullptr;

    // this practice forces you to explicitly point to a place you know
    ptr = new int(10);
    cout << *ptr << endl;
}

int main(void) {
    // problem();
    solution();
    return 0;
}