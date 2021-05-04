// Source : https://leetcode.com/problems/min-stack/
// Author : CrashedBboy
// Date   : 2020-04-01

// Questions
/********************************************************************************** 
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

**********************************************************************************/


// create a custom class to store pushed value and current minimum (the minimum value while pushing it)
class StackNode {
    public:
        int value;
        int currentMin;

        StackNode(int val, int min) {
            value = val;
            currentMin = min;
        }

        StackNode() {}
};


class MinStack {

private:
    vector<StackNode> internalStack;

public:

    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {

        int currentMin;

        if (internalStack.size() == 0) {

            currentMin = numeric_limits<int>::max();

        } else {

            currentMin = internalStack[internalStack.size() - 1].currentMin;
        }

        // update current minimum
        if (x < currentMin) {
            currentMin = x;
        }

        StackNode n;
        n.value = x;
        n.currentMin = currentMin;
        internalStack.push_back(n);
    }
    
    void pop() {

        if (internalStack.size() == 0) {
            return;
        }

        internalStack.pop_back();
    }
    
    int top() {
        
        if (internalStack.size() == 0) {
            return NULL;
        }

        return internalStack[internalStack.size() - 1].value;
    }
    
    int getMin() {
        
        if (internalStack.size() == 0) {
            return NULL;
        }

        return internalStack[internalStack.size() - 1].currentMin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */