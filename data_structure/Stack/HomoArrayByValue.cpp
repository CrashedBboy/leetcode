// stack is homogeneous: hold the data in same data type
// stack is implemented by dynamic array
// stack holds the copy of value

// ways to handle out of memory:
// 1. error code stored in the object indicate the type of error: enum
// 2. throw exception (in C++)
// 3. exit()

class Stack {
public:

    Stack() {
        // allocate the dynamic array with size "INIT_SIZE"
    }
    Stack(size_t size, bool realloc = true) {
        // allocate the dynamic array with the specified size
    }
    ~Stack() {
        // release the obtained memory
    }
    void push(int val) {
        // check if the remained space is enough
        // if not enought and realloc is true, realloc the memory first

        // normal push: increase top & put the val at top
    }
    int pop() {}
    bool empty() {}
    size_t size() {}
private:
    const static int INIT_SIZE = 4;
    size_t _size;
    int top;
};

int main(void) {

    return 0;
}