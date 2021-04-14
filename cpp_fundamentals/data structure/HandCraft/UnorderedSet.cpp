#include <iostream>
#include <unordered_map>

using namespace std;

class UnorderedSet {

public:

    unordered_map<int, bool> table;

    UnorderedSet() {
        table = unordered_map<int, bool>();
    }

    void insert(int value) {
        table[value] = true;
    }

    void erase(int value) {
        table.erase(value);
    }

    bool contains(int value) {
        if (table.find(value) == table.end()) {
            return false;
        }
        else {
            return true;
        }
    }

    static bool identical(UnorderedSet& s1, UnorderedSet& s2) {

        if (s1.size() != s2.size()) {
            return false;
        }

        for (auto& p : s1.table) {
            if (p.second != s2.table[p.first]) {
                return false;
            }
        }

        return true;
    }

    int size() {
        return table.size();
    }

    void print() {

        for (auto& p : table) {
            if (p.second == true) {
                cout << p.first << " ";
            }
        }

        cout << endl;
    }
};

int main() {

    UnorderedSet s1;

    s1.insert(12);
    s1.insert(15);
    s1.insert(1);

    cout << s1.size() << endl;

    s1.print();

    UnorderedSet s2;
    s2.insert(1);
    s2.insert(12);
    s2.insert(15);
    s2.insert(15);
    s2.insert(17);
    s2.erase(17);

    s2.print();

    cout << (UnorderedSet::identical(s1, s2)) << endl;

    return 0;
}