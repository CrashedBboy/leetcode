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
                delete (this->data+i);
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
            if (**(this->data + h)->key == key) {
                **(this->data + h)->value = val;
                return;
            }
            else {
                h += 1;
            }
        }
        *(this->data + h) = new KeyValue(key, val);
        *(this->valid + h) = true;
        this->size += 1;
    }

    // remove data for a specific key
    void clear(int key) {

    }

    int get(int key, bool& found) {

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
            }
            
            // REHASHING
            for (int i = 0; i < this->size; i++) {
                if (*(this->valid+i) == true) {
                    int key = **(this->data+i)->key;
                    int h = this->hash(key);
                    while (*(newValid+h) == true) {
                        h += 1;
                    }
                    *(newValid + h) = true;
                    *(newData + h) = *(this->data + i);
                }
            }

            free(this->valid);
            free(this->data)
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