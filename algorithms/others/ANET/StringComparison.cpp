#include <string>
#include <iostream>

using namespace std;

bool solution1(string& str1, string& str2);
bool solution2(string& s1, string& s2);

int main(void) {

    string str1 = "hello world.";
    string str2 = "farewell, my sweet dream.";
    // string str2 = "hello world.";

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;

    // bool matched = solution1(str1, str2);
    bool matched = solution2(str1, str2);

    cout << "matched? " << (matched?"True":"False") << endl;
    return 0;
}

// char-by-char comparison
// Time complexity: O(N)
bool solution1(string& str1, string& str2) {
    if (str1.size() != str2.size()) {
        return false;
    }
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}

// Time complexity: O(N) + O(N/SAMPLE_RATE) ~ O(N)
bool solution2(string& s1, string& s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    if (s1[0] != s2[0] || s1[s1.size()-1] != s2[s2.size()-1]) {
        return false;
    }
    unsigned int SAMPLE_RATE = 4;
    for (int i = 0; i < s1.size(); i+= SAMPLE_RATE) {
        if (s1[i] != s2[i]) {
            return false;
        }
    }
    return solution1(s1, s2);
}