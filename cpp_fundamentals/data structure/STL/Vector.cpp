// reference: https://www.cplusplus.com/reference/vector/vector/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printVector(vector<int>& v, string name) {

    cout << name << ": [";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "]" << endl;
}

int main() {

    // [declaration]

    int a[] = { 1, 2, 3, 4, 5 };
    cout << "size of a[]: " << (sizeof(a) / sizeof(*a)) << endl;

    vector<int> vec1(a, a + (sizeof(a) / sizeof(*a)));
    printVector(vec1, "vector1");

    vector<int> vec2(vec1);
    printVector(vec2, "vector2");

    vector<int> vec3(vec1.begin(), vec1.end() - 1);
    printVector(vec3, "vector3");

    vector<int> vec4(5, 12);
    printVector(vec4, "vector4");

    vector<int> vec5 = { 5, 4, 3, 2, 1 };
    printVector(vec5, "Vector5");

    // [Access]

    cout << "vec1[2] = " << vec1[2] << endl; // O(1)
    cout << "vec1.front() = " << vec1.front() << endl; // O(1)
    cout << "vec1.back() = " << vec1.back() << endl; // O(1)

    // [Capacity]

    if ( !vec1.empty() ) { // O(1)
        cout << "vec1.size() = " << vec1.size() << endl; // O(1)
    }

    // [Modifier]

    vec1.clear(); // O(N)
    printVector(vec1, "(1)vec1");

    vec1.push_back(10); // O(1)
    vec1.push_back(11);
    vec1.push_back(12);
    vec1.push_back(13);
    vec1.push_back(14);
    printVector(vec1, "(2)vec1");

    vec1.pop_back(); // O(1)
    printVector(vec1, "(3)vec1");

    vec1.resize(2); // O(N)
    printVector(vec1, "(4)vec1");

    vec1.resize(5, 20); // O(N)
    printVector(vec1, "(5)vec1");

    // defined in header <algorithm>
    swap(vec1[0], vec1[1]); // O(1)
    printVector(vec1, "(6)vec1");

    return 0;
}

// push_back(), pop_back(), begin(), end(), front(), back(), size(), empty(), clear(), resize()
