#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct CacheEntry {

    CacheEntry* previous;
    CacheEntry* next;
    int data;
    int key;
};

// my idea: use double hash table to track
// hash table1: <key, value>, hash table2: <timestamp, key>
class LRUCache {
public:
    LRUCache(int capacity) {

        _capacity = capacity;
        cacheSize = 0;
        cacheHead = NULL;
        cacheTail = NULL;
        cache = unordered_map<int, CacheEntry*>();
    }

    int get(int key) {

        if (cache.count(key) == 0 || cache[key] == NULL) {
            return -1;
        }
        else {

            CacheEntry* target = cache[key];

            update(key);

            return target->data;
        }
    }

    void put(int key, int value) {

        if (_capacity <= 0) {
            return;
        }

        if (cache.count(key) > 0 && cache[key] != NULL) {
            cache[key]->data = value;
            update(key);
            return;
        }

        if (cacheSize == _capacity) {

            // remove tail entry

            CacheEntry* target = cacheTail;

            // cout << "Remove: " << target->data << endl;

            cache[target->key] = NULL;

            if (target == cacheHead) {
                cacheTail = cacheHead = NULL;
            }
            else {
                cacheTail = target->previous;
                cacheTail->next = NULL;

            }
            cacheSize -= 1;
        }

        // add new entry
        CacheEntry* newEntry = new CacheEntry();
        newEntry->next = cacheHead;
        if (cacheHead != NULL) {
            cacheHead->previous = newEntry;
        }
        newEntry->previous = NULL;
        newEntry->key = key; newEntry->data = value;
        cache[key] = newEntry;

        cacheHead = newEntry;
        if (cacheTail == NULL) {
            cacheTail = newEntry;
        }
        cacheSize += 1;
    }

    void update(int key) {

        CacheEntry* target = cache[key];

        if (target != cacheHead) {
            if (target == cacheTail) {
                target->previous->next = NULL;
                cacheTail = target->previous;
            }
            else {
                target->previous->next = target->next;
                target->next->previous = target->previous;
            }

            cacheHead->previous = target;
            target->next = cacheHead;
            target->previous = NULL;
            cacheHead = target;
        }
    }

private:
    int _capacity;
    int cacheSize;
    CacheEntry* cacheHead;
    CacheEntry* cacheTail;
    unordered_map<int, CacheEntry*> cache;
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {

    int capacity = 2;
    LRUCache* lruc = new LRUCache(capacity);
    cout << lruc->get(2) << endl;
    lruc->put(2, 6);
    cout << lruc->get(1) << endl;
    lruc->put(1, 5);
    lruc->put(1, 2);
    cout << lruc->get(1) << endl;
    cout << lruc->get(2) << endl;

    return 0;
}