// demo: using realloc to implement a dynamic-length stack

#include <cstdlib>
#include <cassert>
#include <iostream>

using namespace std;

class Stack {
public:
    Stack() {
        this->data = (int*)malloc(sizeof(int) * Stack::INITIAL_SIZE);
        if (this->data == nullptr) {
            cout << "Mem not enough" << endl;
            exit(1);
        }
        this->size = Stack::INITIAL_SIZE;
        this->top = -1;
    }

    void push(int d) {
        this->top += 1;
        *(this->data+this->top) = d;

        if ((this->size - this->top - 1) < RESIZE_N) {
            size_t newSize = (this->size + RESIZE_N*2);
            this->data = (int*)realloc(this->data, sizeof(int) * newSize);
            if (this->data != nullptr) {
                cout << "reiszed to " << newSize << endl;
                this->size = newSize;
            }
            else {
                cout << "failed to reallocate to size " << newSize << endl;
                exit(1);
            }
        }

        for (int i = 0; i <= this->top; i++) {
            cout << *(this->data+i) << ", ";
        }
        cout << endl;
    }

private:
    int* data;
    int top;
    size_t size;
    static const size_t INITIAL_SIZE = 5;
    static const size_t RESIZE_N = 5;
};

int main(void) {

    Stack s;

    for (int i = 0; i < 30; i++) {
        s.push(i);
    }
    return 0;
}