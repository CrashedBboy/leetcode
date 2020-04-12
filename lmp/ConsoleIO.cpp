#include <iostream>
#include <string>

using namespace std;

int main() {

    // read lines from STDIN
    // stop when string len == 0
    while (true) {
    
        cout << "Input: ";

        string inputString;
        std::getline(cin, inputString);

        cout << inputString << endl;

        if (inputString.size() == 0) {
            cout << "[ERROR] please input something, exited" << endl;
            break;
        }
    }

    return 0;
}
