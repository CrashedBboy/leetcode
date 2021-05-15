#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    int min;
    Node* next;
    Node(int x, int min, Node* next) : val(x), min(min), next(next) {}
};

class MinStack {
public:

    MinStack() {
        stack = nullptr;
    }

    void push(int val) {

        if (stack == nullptr) {
            min = val;
            stack = new Node(val, min, nullptr);
        }
        else {
            if (val < min) {
                min = val;
            }
            stack = new Node(val, min, stack);
        }
    }


    void pop() {
        stack = stack->next;
        if (stack != nullptr) {
            min = stack->min;
        }
    }

    int top() {
        return stack->val;
    }

    int getMin() {
        return stack->min;
    }

private:

    Node* stack;
    int min;
};

int main() {

    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // return -3
    minStack.pop();
    cout << minStack.top() << endl;    // return 0
    cout << minStack.getMin() << endl; // return -2

    return 0;
}