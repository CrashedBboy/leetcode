// stack is homogeneous: hold the data in same data type
// stack is implemented by dynamic array
// stack holds the copy of value

// ways to handle out of memory:
// 1. error code stored in the object indicate the type of error: enum
// 2. throw exception (in C++)
// 3. exit()

#include <iostream>
#include <new>

using namespace std;

template <typename T> class StackBase {
public:
    virtual void push(T val) = 0;
    virtual T pop(bool& valid) = 0;
    virtual bool empty() = 0;
    virtual size_t size() = 0;
};

template <typename T> class Stack : public StackBase<T> {
public:
    Stack() {
        // allocate the dynamic array with size "INIT_SIZE"
        this->data = (T*)malloc(Stack::INIT_SIZE * sizeof(T));
        if (this->data == nullptr) {
            cerr << "Stack is running out of memory" << endl;
            throw bad_alloc();
        }
        else {
            this->capacity = Stack::INIT_SIZE;
            this->top = -1;
        }
    }
    Stack(size_t s, bool realloc = true) {
        // allocate the dynamic array with the specified size
        this->data = (T*)malloc(s * sizeof(T));
        if (this->data == nullptr) {
            cerr << "Stack is running out of memory" << endl;
            throw bad_alloc();
        }
        else {
            this->capacity = s;
            this->top = -1;
        }
    }
    ~Stack() {
        // release the obtained memory
        if (this->data != nullptr) {
            free(this->data);
        }
    }
    void push(T val) {
        // check if the remained space is enough
        // if not enought and realloc is true, realloc the memory first
        this->expandCapacityIfNeeded();

        // normal push: increase top & put the val at top
        this->top += 1;
        *(this->data+this->top) = val;
    }
    T pop(bool& valid) {
        if (this->top < 0) {
            valid = false;
            return 0;
        }
        else {
            int popped = *(this->data+this->top);
            this->top -= 1;
            valid = true;
            return popped;
        }
    }
    bool empty() {
        return (this->top == -1);
    }
    size_t size() {
        return (this->top + 1);
    }
    void expandCapacityIfNeeded() {
        if (this->top+2 <= this->capacity) {
            return;
        }
        size_t targetCapacity = 2 * this->capacity;
        
        this->data = (T*)realloc(this->data, sizeof(T)*targetCapacity);
        if (this->data == nullptr) {
            // error handling
            cerr << "Stack is running out of memory" << endl;
            throw bad_alloc();
        }
        else {
            cout << "resized to " << targetCapacity << endl;
            this->capacity = targetCapacity;
        }
    }
private:
    const static int INIT_SIZE = 4;
    int capacity;
    int top;
    T* data;
};

int main(void) {

    Stack<int> s1;
    for (int i = 0; i < 3; i++) { s1.push(i*3); }
    for (int i = 0; i < 3; i++) {
        bool valid = false;
        int popped = s1.pop(valid);
        if (valid) {
            cout << popped << ",";
        }
    }
    cout << endl;

    Stack<char> s2;
    for (int i = 0; i < 3; i++) { s2.push((char)('a'+i)); }
    for (int i = 0; i < 3; i++) {
        bool valid = false;
        char popped = s2.pop(valid);
        if (valid) {
            cout << popped << ",";
        }
    }
    cout << endl;


    /*
    size_t N = 20000000000;
    try {
        Stack s (2);
        for (int i = 0; i < N; i++) {
            s.push(i);
        }

        bool valid = false;
        for (int i = 0; i < N+1; i++) {
            int popped = s.pop(valid);
            if (valid) {
                // cout << popped << ",";
            }
            else {
                cout << "no item left!, ";
            }
        }
        cout << endl;
    }
    catch (...) {
        cout << "bad alloc caught" << endl;
        exit(1);
    }
    */

    return 0;
}