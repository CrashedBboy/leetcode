#include <iostream>
#include <string>

using namespace std;

int main() {

    // [declaration]

    char ca[] = {'s', 'o', 'm', 'e', 't', 'h', 'i', 'n', 'g'};
    string str1(ca, sizeof(ca)/sizeof(*ca)); // -> string str1(ca, 9)

    string str2 = "something new";

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;

    // [assign]
    str1 = ":)";
    cout << "str1: " << str1 << endl;

    // [concat]
    str2 += str1;
    cout << "str2: " << str2 << endl;

    // [access]
    for (int i = 0; i < str2.size(); i++) {
        
        if (str2[i] == 'e') {
            cout << "found 'e' at position " << i << endl;
        }
    }

    return 0;
}
