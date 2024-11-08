#include <iostream>
#include <cassert>

using namespace std;

enum class DataType {
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
        if (ContainerNode::isSupportedType(val)) {
            this->data = malloc(sizeof(T));
            *((T*)this->data) = val;
            this->type = ContainerNode::lookupDataType(val);
        }
        else {
            cerr << "Not supported data type!" << endl;
            exit(1);
        }
    }

    ~ContainerNode() {
        free(this->data);
    }

    void* data;
    DataType type;

    DataType getDataType() {
        return this->type;
    }

    template <typename T>
    static bool isSupportedType(T val) {
        if (typeid(val) == typeid(int) || typeid(val) == typeid(char) || typeid(val) == typeid(float)) {
            return true;
        }
        return false;
    }

    template <typename T>
    static DataType lookupDataType(T val) {
        if (typeid(val) == typeid(int)) {
            return DataType::Int;
        }
        else if ( typeid(val) == typeid(char)) {
            return DataType::Char;
        }
        else if (typeid(val) == typeid(float)) {
            return DataType::Float;
        }
        else {
            return DataType::NotSupported;
        }
    }
};

class DynamicArrayStack {
public:
    DynamicArrayStack(size_t initCapacity) {
        // allocate the memroy
        this->data = (ContainerNode**)malloc( initCapacity * sizeof(ContainerNode*));
        if (this->data != nullptr) {
            // update capacity
            this->capacity = initCapacity;
            this->top = -1;
        }
        else {
            this->errorOutOfMemory();
        }
    }
    DynamicArrayStack() {
        // allocate the memroy
        this->data = (ContainerNode**)malloc( DynamicArrayStack::INIT_SIZE * sizeof(ContainerNode*));
        if (this->data != nullptr) {
            // update capacity
            this->capacity = DynamicArrayStack::INIT_SIZE;
            this->top = -1;
        }
        else {
            this->errorOutOfMemory();
        }
    }

    ~DynamicArrayStack() {
        // free every remained ContainerNode* in the dynamic array
        for (int i = this->top; i > -1; i--) {
            ContainerNode* n = *(this->data + i);
            delete n;
            *(this->data + i) = nullptr;
        }
        free(this->data); 
        this->data = nullptr;
    }

    template <typename T>
    void push(T val) {
        // expand the size if needed
        if ((this->capacity - this->top) == 1) {
            int targetCapacity = this->capacity * 2;
            this->data = (ContainerNode**)realloc(this->data, targetCapacity * sizeof(ContainerNode*));
            if (this->data != nullptr) {
                this->capacity = targetCapacity;
                cout << "capacity expanded to " << this->capacity << endl;
            }
            else {
                this->errorOutOfMemory();
            }
        }

        // increase top by one, fill in the val
        this->top += 1;
        ContainerNode* newNode = new ContainerNode(val);
        *(this->data + this->top) = newNode;
    }

    template <typename T>
    T pop(bool& valid) {
        if (this->empty()) {
            valid = false;
        }
        else {
            ContainerNode* topNode = *(this->data + this->top);
            T answer = *(T*)(topNode->data);
            this->top -= 1;
            valid = true;
            delete topNode;
            return answer;
        }
        return (T)NULL;
    }

    DataType peekTopType() {
        if (this->empty()) {
            return DataType::NotSupported;
        }
        else {
            return (*(this->data + this->top))->getDataType();
        }
    }

    bool empty() {
        return this->top == -1;
    }

    size_t size() {
        return (this->top+1);
    }

    void errorOutOfMemory() {
        cerr << "Out of memory: " << (this->top + 1) << endl;
    }

private:
    const static int INIT_SIZE = 4;
    unsigned int capacity;
    ContainerNode** data;
    int top;
};

int main(void) {

    DynamicArrayStack s(1);
    s.push<char>('a');
    s.push<int>(100);
    s.push<char>('b');
    s.push<float>(3.14);
    s.push<char>('c');

    while (!s.empty()) {
        DataType dt = s.peekTopType();
        bool valid;
        int valInt;
        float valFloat;
        char valChar;
        switch (dt) {
            case DataType::Int:
                valInt = s.pop<int>(valid);
                cout << valInt << ",";
                break;
            case DataType::Float:
                valFloat = s.pop<float>(valid);
                cout << valFloat << ",";
                break;
            case DataType::Char:
                valChar = s.pop<char>(valid);
                cout << valChar << ",";
                break;
            default:
                cout << "<?>,";
        }
    }

    return 0;
}