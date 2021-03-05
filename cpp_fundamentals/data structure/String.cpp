// reference: http://www.cplusplus.com/reference/string/string/

#include <iostream>
#include <string>

using namespace std;

int main() {

    // [constructor]

    // build from char array
    char ca[] = {'A', 'B', 'C'};
    string str1 (ca, sizeof(ca) / sizeof(*ca)); // -> string str1(ca, 3)

    // build from null-terminated char array
    char cb[] = {'A', 'B', 'C', 0};
    string str2 (cb);

    // assign const string
    string str3 = "ABC";

    // fill
    string str4 (3, 'A');

    // copy
    string origin = "XYZ";
    string str5 (origin);

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    cout << "str4: " << str4 << endl;
    cout << "str5: " << str5 << endl;

    // [concat]
    str2 += "XYZ";
    cout << "str2: " << str2 << endl;

    // [access & modify]
    cout << str1[1] << endl;
    str1[1] = 'D';
    cout << str1 << endl;

    // [push & pop]
    str1.push_back('Y');
    str1.push_back('Z');
    str1.push_back('Z');
    str1.pop_back();
    cout << str1 << endl;

    return 0;
}
