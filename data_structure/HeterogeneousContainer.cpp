#include <iostream>
#include <stdexcept>

class HeterogeneousContainer {
private:
    union Data {
        int intValue;
        float floatValue;
        char charValue;

        Data() {}  // Default constructor
        ~Data() {} // Destructor to allow safe destruction
    };

    Data data;
    enum class DataType {
        None,
        Integer,
        Float,
        Char
    } type;

public:
    // Constructor
    HeterogeneousContainer() : type(DataType::None) {}

    // Destructor
    ~HeterogeneousContainer() {
        clear();
    }

    // Store an integer
    void set(int value) {
        clear();
        data.intValue = value;
        type = DataType::Integer;
    }

    // Store a float
    void set(float value) {
        clear();
        data.floatValue = value;
        type = DataType::Float;
    }

    // Store a char
    void set(char value) {
        clear();
        data.charValue = value;
        type = DataType::Char;
    }

    // Retrieve the stored integer
    int getInt() const {
        if (type != DataType::Integer) {
            throw std::runtime_error("Data type is not Integer!");
        }
        return data.intValue;
    }

    // Retrieve the stored float
    float getFloat() const {
        if (type != DataType::Float) {
            throw std::runtime_error("Data type is not Float!");
        }
        return data.floatValue;
    }

    // Retrieve the stored char
    char getChar() const {
        if (type != DataType::Char) {
            throw std::runtime_error("Data type is not Char!");
        }
        return data.charValue;
    }

    // Clear the current data
    void clear() {
        type = DataType::None;
    }

    // Get the current type
    std::string getType() const {
        switch (type) {
            case DataType::None: return "None";
            case DataType::Integer: return "Integer";
            case DataType::Float: return "Float";
            case DataType::Char: return "Char";
        }
        return "Unknown";
    }
};

int main() {
    HeterogeneousContainer container;

    // Store an integer
    container.set(42);
    std::cout << "Stored type: " << container.getType() << ", Value: " << container.getInt() << std::endl;

    // Store a float
    container.set(3.14f);
    std::cout << "Stored type: " << container.getType() << ", Value: " << container.getFloat() << std::endl;

    // Store a char
    container.set('A');
    std::cout << "Stored type: " << container.getType() << ", Value: " << container.getChar() << std::endl;

    return 0;
}