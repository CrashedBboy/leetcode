#include <iostream>
#include <vector>

using namespace std;

class Person {
private:
    int _height;
    int _weight;
    int _count;
public:

    Person(int height = 0, int weight = 0) : _count(0) {
        _height = height;
        _weight = weight;
    }

    int getHeight() {
        return _height;
    }

    int getWeight() {
        return _weight;
    }

    int getCount() {
        return _count;
    }
};

int main() {

    Person* me = new Person(185, 75);

    cout << "my height = " << me->getHeight() << ", my count = " << me->getCount() <<endl;

    delete me;

    return 0;
}