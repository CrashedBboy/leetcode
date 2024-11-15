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

            KeyValue** newData = (KeyValue**)realloc(this->data, newSize * sizeof(KeyValue*));
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
                    int key = (*(this->data+i))->key;
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

    HashTable ht;

    ht.set(3, 1);
    ht.set(4, 1);

    bool found = false;
    int v = ht.get(5, found);
    if (found) {
        cout << "yes" << endl;
    }
    else {
        cout << "not found" << endl;
    }

    // test data integrity :
    /*
    1. set set get
    2. set clear get
    */
    // test size dynamically allocation: reallocation & re-hashing
    /*
    1. set->set->set-> ...(resizing) ->set ->get->get->get...
    */


    return 0;
}
