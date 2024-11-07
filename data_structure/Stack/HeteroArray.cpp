#include <iostream>

using namespace std;

enum class ContainerType {
    Int,
    Char,
    Float,
    NotSupported
};

class ContainerNode {
public:
    ContainerNode() = delete;

    template <typename T>
    ContainerNode(T val) {
        this->data = new T(val);

        if (ContainerNode::isSupportedType(val)) {
            this->data = new T(val);
            this->type = ContainerNode::getContainerType(val);
        }
        else {
            cerr << "Not supported data type!" << endl;
            exit(1);
        }
    }
    void* data;
    ContainerType type;

    template <typename T>
    static bool isSupportedType(T val) {
        if (typeid(val) == typeid(int) || typeid(val) == typeid(char) || typeid(val) == typeid(float)) {
            return true;
        }
        return false;
    }

    template <typename T>
    static ContainerType getContainerType(T val) {
        if (typeid(val) == typeid(int)) {
            return ContainerType::Int;
        }
        else if ( typeid(val) == typeid(char)) {
            return ContainerType::Char;
        }
        else if (typeid(val) == typeid(float)) {
            return ContainerType::Float;
        }
        else {
            return ContainerType::NotSupported;
        }
    }
};

class DynamicArrayStack {
public:
    DynamicArrayStack(size_t initCapacity) {

        // allocate the memroy

        // update capacity
    }
    DynamicArrayStack() {

        // allocate the memroy

        // update capacity
    }

    ~DynamicArrayStack() {

    }

    template <typename T>
    void push(T val) {

    }

    template <typename T>
    T pop(bool& valid) {
        return (T)0;
    }

    ContainerType peekTopType() {
        return ContainerType::NotSupported;
    }

    bool empty() {
        return true;
    }

    size_t size() {
        return 0;
    }

private:
    const static int INIT_SIZE = 4;
    unsigned int capacity;
};



int main(void) {

    return 0;
}