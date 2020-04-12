#include <iostream>
#include <queue>

using namespace std;

int main() {

    queue<int> q;

    q.push(12);
    q.push(24);
    q.push(36);

    q.pop();

    if (!q.empty()) {
        cout << "queue size: " << q.size() << endl;
        cout << "queue front: " << q.front() << endl;
        cout << "queue back: " << q.back() << endl;
    }

    return 0;
}