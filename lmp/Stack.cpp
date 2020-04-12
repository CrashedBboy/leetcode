#include <iostream>
#include <stack>

using namespace std;


int main() {

    stack<int> s;

    s.push(12);
    s.push(10);

    s.pop();

    if (!s.empty()) {
        cout << "stack size: " << s.size() << endl;

        cout << "stack top: " << s.top() << endl;
    }
    

    return 0;
}