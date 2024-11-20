#include <iostream>


using namespace std;

class Node {
public:
    Node(int k, int v, int psl): key(k), value(v), psl(psl) {}
    int key;
    int value;
    int psl; // probe sequence lengths
};


class HashTable {
public:
    HashTable() {
        this->data = (Node**)malloc(HashTable::INIT_SIZE * sizeof(Node*));
        this->valid = (bool*)calloc(HashTable::INIT_SIZE, sizeof(bool));
        if (!this->data || !this->valid) {
            this->error();
        }
        else {
            this->size = 0;
            this->capacity = HashTable::INIT_SIZE;
        }
    }
    ~HashTable() {
        // release every Node
        // release this->data
        // release this->valid
    }
    void set(int key, int val) {
        // probing: goes linearly, along the way, keep checking each one's psl, looking for replacement
        // probing stop condition: 1. find the rich 2. find the empty
    }
    int get(int key, bool& found) {
        // probing: a simple linear probing
        // probing stop condition: 1. find the target key 2. find the empty
    }
    void clear(int key) {
        // probing: linear probing
        // probing stop condition: 1. find the target key 2. find the empty

        // remove the object (remember to free the Node*)

        // shift the object behind which has non-zero psl
    }
private:
    const static int INIT_SIZE;
    Node** data;
    bool* valid;
    int capacity;
    int size;
    int hash() {}
    void resizeIfNeeded() {}
    void error() {
        cout << "bad allocation" << endl;
        exit(1);
    }
};


int main (void) {

    bool found = false;
    int res = -1;

    // set -> set (overwrite) -> get
    HashTable ht1;
    ht1.set(3, 1);
    ht1.set(3, 12);
    res = ht1.get(3, found);
    if (res != 12 || found == false) {
        cout << "test failed" << endl;
        return 0;
    }

    // set -> clear -> get
    ht1.clear(3);
    res = ht1.get(3, found);
    if (res == 12 || found == true) {
        cout << "test failed" << endl;
        return 0;
    }

    // test size dynamically allocation: reallocation & re-hashing
    int N = 100000;
    for (int i = 0; i < N; i++) {
        ht1.set(i, i * 3);
    }
    for (int i = 0; i < N; i++) {
        res = ht1.get(i, found);
        if (!found || res != i*3) {
            cout << "test failed" << endl;
            return 0;
        }
    }

    cout << "test passed" << endl;

    return 0;
}