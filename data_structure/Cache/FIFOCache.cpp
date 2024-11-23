#include <iostream>
#include <unordered_map>
#include <cassert>
#include <vector>

using namespace std;

class FIFOCache {
public:
    FIFOCache(int c): capacity(c) {
        assert((c > 0));
        this->head = -1;
        this->tail = 0;
        this->size = 0;
        this->keys = vector<int>(c, -1);
    }

    ~FIFOCache() {}

    void put(int k, int v) {
        unordered_map<int, int>::iterator it = this->keyToValue.find(k);
        if (it == this->keyToValue.end()) {
            if (this->size == this->capacity) {
                // evict
                int keyToGo = this->keys[this->tail];
                this->keyToValue.erase(keyToGo);
                this->tail = (this->tail + 1) % this->capacity;
                this->size -= 1;
                cout << "Evict key: " << keyToGo << endl;
            }
            this->head = (this->head + 1) % this->capacity;
            this->keyToValue[k] = v;
            this->keys[this->head] = k;
            this->size += 1;
        }
        else {
            it->second = v;
        }
    }

    int get(int k, bool& found) {
        int defaultAns;
        unordered_map<int, int>::iterator it = this->keyToValue.find(k);
        if (it != this->keyToValue.end()) {
            found = true;
            return it->second;
        }
        else {
            found = false;
            return defaultAns;
        }
    }
private:
    unordered_map<int, int> keyToValue;
    vector<int> keys; // stores keys
    int head;
    int tail;
    int capacity;
    int size;
};

int main (void) {
    FIFOCache c1 (3);
    c1.put(1,1);
    c1.put(2,2);
    c1.put(3,3);
    int ans;
    bool found;
    ans = c1.get(1, found);
    if (!found || ans != 1) {
        cout << "test 1 failed" << endl;
        exit (1);
    }
    c1.put(4,4); // should evict 1
    ans = c1.get(1, found);
    if (found) {
        cout << "test 2 failed" << endl;
        exit (1);
    }
    cout << "all tests passed" << endl;

    return 0;
}