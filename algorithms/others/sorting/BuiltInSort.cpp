#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
private:
    int _height;
    int _weight;
public:
    Person(int height = 0, int weight = 0) {
        _height = height;
        _weight = weight;
    }

    int getHeight() {
        return _height;
    }

    int getWeight() {
        return _weight;
    }

    static bool comp(Person p1, Person p2) {
        return p1.getHeight() < p2.getHeight();
    }

    static void print(vector<Person> users) {
        for (int i = 0; i < users.size(); i++) {
            cout << users[i].getHeight() << " ";
        }
        cout << endl;
    }
};

int main() {

    vector<Person> users;
    Person p1(180, 75);
    Person p2(170, 70);
    Person p3(189, 75);
    users.push_back(p1);
    users.push_back(p2);
    users.push_back(p3);
    Person::print(users);

    sort(users.begin(), users.end(), Person::comp);

    Person::print(users);

    return 0;
}