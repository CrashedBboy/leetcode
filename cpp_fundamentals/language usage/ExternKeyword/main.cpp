#include <iostream>
#include "data.h"

using namespace std;

extern int a;
// Key points: "declaration vs definition", "extern" keyword
// It "declare" the variable. And we use 'extern' keyword to indicate
// that the variable will be "defined" at external scopes

// It the definition of a is missing at data.h, linker will report the error

int main (void) {

    if (a > 0) {
        cout << "A is greater than zero" << endl;
    }

    return 0;
}