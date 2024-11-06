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

template <typename T> class StackNode {
public:
    StackNode(): next(nullptr) {}
    StackNode(T v): val(v), next(nullptr) {}
    StackNode(T v, StackNode<T>* nxt): val(v), next(nxt) {}
    T val;
    StackNode<T>* next;
};

template <typename T> class Stack : public StackBase<T> {
public:
    Stack() {
        top = nullptr;
        nodeCount = 0;
    }
    void push(T val) {
        StackNode<T>* newNode = new StackNode<T>(val, this->top);
        this->nodeCount += 1;
        this->top = newNode;
    }
    T pop(bool& valid) {
        if (this->top == nullptr) {
            valid = false;
            return (T)NULL;
        }
        else {
            valid = true;
            StackNode<T>* prev = this->top;
            T popped = prev->val;
            this->top = prev->next;
            this->nodeCount -= 1;
            free(prev);
            return popped;
        }
    }
    bool empty() {
        return this->nodeCount == 0;
    }
    size_t size() {
        return this->nodeCount;
    }
    ~Stack() {
        // todo: release all linked node's memory
        StackNode<T>* tmp = this->top;
        while (tmp != nullptr) {
            StackNode<T>* prev = tmp;
            tmp = tmp->next;
            free(prev);
        }
    }
private:
    StackNode<T>* top;
    unsigned int nodeCount;
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


    return 0;
}