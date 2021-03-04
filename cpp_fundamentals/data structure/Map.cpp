#include <iostream>
#include <map>
#include <string>

using namespace std;

void printMap(map<string, int>, string);

int main() {

    // [construct]
    map<string, int> userHeights = { {"Austin", 175}, {"John", 182} }; // by default map is container of Pair
    map<string, int> userAges;

    userAges["Austin"] = 22;
    userAges["John"] = 28;

    printMap(userHeights, "user heights");
    printMap(userAges, "user ages");

    // [assign] [access]
    userHeights["Austin"] = 185;
    userHeights["Jaa"] = 157;
    printMap(userHeights, "user heights");

    // [search]
    cout << "How many Jaa: " << userHeights.count("Jaa") << endl;

    return 0;
}

void printMap(map<string, int> m, string name) {

    cout << name << ": { ";
    for (auto p : m) {
        cout << p.first << ": " << p.second << ", ";
    }
    cout << " }" << endl;
}