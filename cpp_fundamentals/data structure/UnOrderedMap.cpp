// reference: https://www.cplusplus.com/reference/unordered_map/unordered_map/

#include <unordered_map>
#include <iostream>
#include <utility> // for pair
#include <string>

using namespace std;

typedef pair<string, int> mapping;

int main() {

    // declaration
    unordered_map<string, int> map = {{"John", 12}, {"Alice", 22}};
    
    // add new entry
    map.insert(mapping ("Dave", 33) );

    // iterate entries
    for (auto& m : map) {
        cout << m.first << ": " << m.second << endl;
    }

    // count for entries
    cout << "Entry number: " << map.size() << endl;

    // delete entry by key
    map.erase("Dave");
    for (auto& m : map) {
        cout << m.first << ": " << m.second << endl;
    }

    // empty all
    map.erase(map.begin(), map.end());
    cout << map.size() << endl;

    return 0;
}


// important: pair<T, T>, insert(), for (auto& item: map), erase(), size(), count()