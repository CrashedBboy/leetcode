// The Diamond Inheritance problem

#include <iostream>

using namespace std;

class A {
public:
    A() { cout << "A created" << endl; }
    ~A() { cout << "A destructed" << endl; }
    void display() { cout << "This is A." << endl; }
};

class B: virtual public A {
public:
    B() { cout << "B created" << endl; }
    ~B() { cout << "B destructed" << endl; }
};

class C: virtual public A {
public:
    C() { cout << "C created" << endl; }
    ~C() { cout << "C destructed" << endl; }
};

class D: public B, public C {
public:
    D() { cout << "D created" << endl; }
    ~D() { cout << "D destructed" << endl; }
};

int main(void) {

    D d;
    d.display();

    return 0;
}
/*
The Diamond Inheritance Problem:

without virtual inheritance, the compilation fails with the error message:

        ./DiamondInheritance.cpp: In function ‘int main()’:
        ./DiamondInheritance.cpp:35:7: error: request for member ‘display’ is ambiguous
        35 |     d.display();
            |       ^~~~~~~
        ./DiamondInheritance.cpp:11:10: note: candidates are: ‘void A::display()’
        11 |     void display() { cout << "This is A." << endl; }
            |          ^~~~~~~
        ./DiamondInheritance.cpp:11:10: note:                 ‘void A::display()’

Because both B and C inheritated by D create an instance of A. 
So it's not clear which A instance's display() to be executed.

To solve the problem, we can use virtual inheritance, which will keeps only one instance of A.
In that way it solves the duplication and ambiguity.

How virtual inheritance works:
Virtual inheritance introduces a level of indirection. 
The derived classes (B and C) maintain pointers to the shared instance of the virtual base class (A).
*/

/*
Program output:
    A created
    B created
    C created
    D created
    This is A.
    D destructed
    C destructed
    B destructed
    A destructed
*/
