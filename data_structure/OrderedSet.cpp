#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

class OrderedSet {

public:

    OrderedSet() {
        bst = new BinarySearchTree(true);
    }

    void insert(int x) {
        bst->insert(x);
    }

    bool contains(int x) {
        return bst->contains(x);
    }

    void erase(int x) {
        bst->erase(x);
    }

    void print() {
        bst->getSortedSequence();
    }

private:

    BinarySearchTree* bst;
};

int main () {

    OrderedSet set;

    set.insert(12);
    set.insert(12);
    set.insert(12);
    set.insert(15);
    set.insert(18);

    set.erase(12);

    cout << set.contains(18) << endl;

    set.print();
}