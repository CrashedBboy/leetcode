// reference: http://www.cplusplus.com/reference/unordered_set/unordered_set/

#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

void print (unordered_set<int>& s) {
    cout << "{ ";
    for (auto& item : s) {
        cout << item << ",";
    }
    cout << " }" << endl;
}

int main () {

    // declaration: built from array
    vector<int> nums = {12, 12, 3, 4, 7};
    unordered_set<int> s1 (nums.begin(), nums.end());
    print(s1);

    // declaration: copy
    unordered_set<int> s2 (s1);
    print(s2);

    // declaration: create an empty set
    unordered_set<int> s3;

    // insert items
    s3.insert(13); s3.insert(13); s3.insert(2); s3.insert(4);
    print(s3);

    // remove item
    // by position: erase ( const_iterator position );
    // by key: erase ( const key_type& k );
    // range: erase ( const_iterator first, const_iterator last );
    nums = {1,2,3,4,5,6,7,8,9,10};
    unordered_set<int> s4 (nums.begin(), nums.end());
    
    s4.erase(s4.begin(), s4.find(3)); // will not delete 3 (remove elements before 3)
    print(s4);

    s4.erase(s4.find(9));
    print(s4); // delete by address (iterator)

    s4.erase(7);
    print(s4); // delete by key

    // check for existence of item
    unordered_set<int> s5 (nums.begin(), nums.end());
    if (s5.find(11) == s5.end()) {
        cout << "11 not found in s5" << endl;
    }

    // iterate all items: range-based loop
    for (auto& item : s1) {  }

    // iterate all items: using iterator
    for (unordered_set<int>::iterator it = s2.begin(); it != s2.end(); it++) {
        int n = *it;
    }

    // remove all items & get set size
    unordered_set<int> s6 (nums.begin(), nums.end());
    s6.clear();
    cout << "s6 size: " << s6.size() << endl;

    return 0;
}

// <unordered_map>
// insert(), begin(), end(), clear(), empty(), size(), erase(), find()