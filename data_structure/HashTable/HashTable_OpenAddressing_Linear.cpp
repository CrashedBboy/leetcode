#include <iostream>
#include <cstring>

using namespace std;

class KeyValue {
public:
    int key;
    int value;
    KeyValue(int k, int v): key(k), value(v) {}
};

class HashTable {
public:
    HashTable() {
        // init capacity & storage
        this->data = (KeyValue**)malloc(HashTable::INIT_SIZE * sizeof(KeyValue*));
        this->valid = (bool*)calloc(HashTable::INIT_SIZE, sizeof(bool));
        if (this->data == nullptr || this->valid == nullptr) {
            this->errorAlloc();
        }
        else {
            this->capacity = HashTable::INIT_SIZE;
            this->size = 0;
        }
    }

    ~HashTable() {
        // release all Key-Value pair in the array
        for (int i = 0; i < this->size; i++) {
            if (*(this->valid+i) == true) {
                delete *(this->data+i);
            }
        }
        // release the array
        free(this->data);
        free(this->valid);
    }

    void set(int key, int val) {
        this->resizeIfNeeded();
        int h = this->hash(key);
        while (*(this->valid + h) == true) {
            if ((*(this->data + h))->key == key) {
                (*(this->data + h))->value = val;
                return;
            }
            else {
                h = (h + 1)%this->capacity;
            }
        }
        *(this->data + h) = new KeyValue(key, val);
        *(this->valid + h) = true;
        this->size += 1;
    }

    // remove data for a specific key
    void clear(int key) {
        int h = this->hash(key);
        while( *(this->valid + h) == true) {
            if ((*(this->data + h))->key == key) {
                delete (*(this->data + h));
                *(this->valid + h) = false;
                this->size -= 1;
                return;
            }
            else {
                h = (h + 1) % this->capacity;
            }
        }
    }

    int get(int key, bool& found) {
        found = false;
        int h = this->hash(key);
        while ( *(this->valid + h) == true ) {

            if ( (*(this->data + h))->key == key ) {
                found = true;
                return (*(this->data + h))->value;
            }
            else {
                h = (h + 1) % this->capacity;
            }
        }

        return -1;
    }

private:
    const static size_t INIT_SIZE = 4;
    KeyValue** data;
    bool* valid;
    size_t capacity;
    size_t size;
    void resizeIfNeeded() {
        if (this->capacity == this->size) {
            size_t newSize = this->capacity * 2;

            KeyValue** newData = (KeyValue**)malloc(newSize * sizeof(KeyValue*));
            bool* newValid = (bool*)calloc(newSize, sizeof(bool));
            if (newData == nullptr || newValid == nullptr) {
                this->errorAlloc();
            }
            else {
                this->capacity = newSize;
                cout << "Size has been resized to " << this->capacity << endl;
            }
            
            // REHASHING
            for (int i = 0; i < this->size; i++) {
                if (*(this->valid+i) == true) {
                    int key = (*(this->data + i))->key;
                    int h = this->hash(key);
                    while (*(newValid+h) == true) {
                        h = (h + 1) % this->capacity;
                    }
                    *(newValid + h) = true;
                    *(newData + h) = *(this->data + i);
                }
            }

            free(this->valid);
            free(this->data);
            this->valid = newValid;
            this->data = newData;
        }
    }
    void errorAlloc() {
        cerr << "Cannot allocate memory from " << this->capacity << endl;
        exit(1);
    }

    int hash(int key) {
        return key % this->capacity;
    }
};

int main (void) {

    bool found = false;
    int res = -1;

    // test data integrity :
    /*
    1. set set get
    2. set clear get
    */

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
    /*
    1. set->set->set-> ...(resizing) ->set ->get->get->get...
    */

    cout << "test passed" << endl;

    return 0;
}
