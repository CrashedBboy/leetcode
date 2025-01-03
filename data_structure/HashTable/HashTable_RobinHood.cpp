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
        for (int i = 0; i < this->capacity; i++) {
            if ( *(this->valid + i) == true ) {
                delete *(this->data + i);
            }
        }
        // release this->data
        free (this->valid);
        this->valid = nullptr;
        // release this->valid
        free (this->data);
        this->data = nullptr;
    }

    void set(int key, int val) {
        // two scenarios: 1. the key exists in the table 2. the key is new
        bool found = false;
        int index = -1;
        int foo = this->internalGet(key, found, index);
        if (found) {
            (*(this->data + index))->value = val;
            return;
        }
        else {
            this->resizeIfNeeded();
            int home = this->hash(key);
            int psl = 0;
            Node* newNode = new Node(key, val, 0);
            Node* it = newNode;
            while (it != nullptr) {
                int offset = (home + psl) % this->capacity;
                if ( *(this->valid + offset) == true ) {
                    if (psl > (*(this->data + offset))->psl ) {
                        // here comes the robin hood
                        Node* nodeBeingVisited = *(this->data + offset);
                        it->psl = psl;
                        *(this->data + offset) = it;
                        it = nodeBeingVisited;
                        home = this->hash(nodeBeingVisited->key);
                        psl = nodeBeingVisited->psl;
                        psl += 1;
                    }
                    else {
                        psl += 1;
                    }
                }
                else {
                    it->psl = psl;
                    *(this->data + offset) = it;
                    *(this->valid + offset) = true;
                    it = nullptr;
                }
            }
            this->size += 1;
        }
        // https://programming.guide/robin-hood-hashing.html
        // probing: goes linearly, along the way, keep checking each one's psl, looking for replacement
        // probing stop condition: 1. find the rich 2. find the empty
    }
    int get(int key, bool& found) {
        int index = -1;
        return this->internalGet(key, found, index);
    }
    void clear(int key) {
        int h = this->hash(key);
        // probing: linear probing
        // probing stop condition: 1. find the target key 2. find the empty
        Node* it;
        while( *(this->valid + h) == true ) {
            it = *(this->data + h);
            if ( it->key == key) {
                // remove the object (remember to free the Node*)
                delete it;
                *(this->valid + h) = false;
                *(this->data + h) = nullptr;
                this->size -= 1;
                // shift the object behind which has non-zero psl
                int prev = h;
                int i = (prev + 1) % this->capacity;
                while ( *(this->valid + i) == true && (*(this->data + i))->psl != 0 ) {
                    (*(this->data + i))->psl -= 1;
                    *(this->data + prev) = *(this->data + i);
                    *(this->valid + i) = false;
                    *(this->data + i) = nullptr;
                    prev = i;
                    i = (i+1) % this->capacity;
                }
                return;
            }
            else {
                h = (h + 1) % this->capacity;
            }
        }
    }
private:
    const static int INIT_SIZE = 7;
    Node** data;
    bool* valid;
    int capacity;
    int size;
    int hash(int key) {
        return key % this->capacity;
    }

    void resizeIfNeeded() {
        if (this->size < this->capacity) {
            return;
        }

        // calculate new capacity
        int newCapacity = 2 * this->capacity;

        // acquire new location
        Node** newData = (Node**)malloc(newCapacity * sizeof(Node*));
        bool* newValid = (bool*)calloc(newCapacity, sizeof(bool));
        if (newData == nullptr || newValid == nullptr) {
            this->error();
        }
        int oldCapacity = this->capacity;
        this->capacity = newCapacity;

        // rehashing
        for (int i = 0; i < oldCapacity; i++) {
            if ( *(this->valid + i) == true ) {

                Node* nodeToGo = *(this->data + i);
                int key = nodeToGo->key;

                // insert with robin hood mechanism
                int home = this->hash(key);
                int psl = 0;
                Node* it = nodeToGo;
                while (it != nullptr) {
                    int offset = (home + psl) % this->capacity;
                    if ( *(newValid + offset) == true ) {
                        // compare the psl
                        Node* nodeBeingVisited = *(newData + offset);
                        if (psl > nodeBeingVisited->psl) {
                            it->psl = psl;
                            *(newData + offset) = it;
                            it = nodeBeingVisited;
                            home = this->hash(nodeBeingVisited->key);
                            psl = nodeBeingVisited->psl;
                            psl += 1;
                        }
                        else {
                            psl += 1;
                        }
                    }
                    else {
                        it->psl = psl;
                        *(newData + offset) = it;
                        *(newValid + offset) = true;
                        it = nullptr;
                    }
                }
            }
        }
        free(this->data);
        free(this->valid);
        this->data = newData;
        this->valid = newValid;
    }

    int internalGet(int key, bool& found, int& index) {
        int h = this->hash(key);
        // probing: a simple linear probing
        // probing stop condition: 1. find the target key 2. find the empty
        found = false;
        for (int i = 0; i < this->capacity; i++) {
            if ( *(this->valid + h) && (*(this->data + h))->key == key ) {
                found = true;
                index = h;
                return (*(this->data + h))->value;
            }
        }
        return -1;
    }
    void error() {
        cout << "bad allocation (size=" << this->size << ")" << endl;
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
        cout << "test1 failed" << endl;
        return 0;
    }
    cout << "test1 passed" << endl;

    // set -> clear -> get
    ht1.clear(3);
    res = ht1.get(3, found);
    if (res == 12 || found == true) {
        cout << "test2 failed" << endl;
        return 0;
    }
    cout << "test2 passed" << endl;

    // test size dynamically allocation: reallocation & re-hashing
    int N = 10;
    for (int i = 0; i < N; i++) {
        ht1.set(i, i * 3);
    }
    for (int i = 0; i < N; i++) {
        res = ht1.get(i, found);
        if (!found || res != i*3) {
            cout << "test3 failed" << endl;
            return 0;
        }
    }
    cout << "test3 passed" << endl;

    cout << "test passed" << endl;

    return 0;
}