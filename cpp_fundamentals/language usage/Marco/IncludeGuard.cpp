#include <iostream>
#include "IncludeGuard.h"

using namespace std;

// let's say we accidentally include the same header again
#include "IncludeGuard.h"

extern int data_a;
int main() {
    cout << data_a << endl;
}