#include <iostream>
#include <unordered_map>

using namespace std;

// doubly-linked list
class DNode {
public:
    DNode* prev;
    DNode* next;
    int key;
    int val;
    DNode(int key, int val): prev(nullptr), next(nullptr), key(key), val(val) {}
};

// LRU Cache
class LRUCache {
public:
    LRUCache(int c): head(nullptr), tail(nullptr), size(0), capacity(c) {
        if (c < 1) {
            cerr << "Cache capacity cannot be lower than 1" << endl;
            exit(1);
        }
    }
    ~LRUCache() {
        // release all DNode
        DNode* it = this->head;
        while (it != nullptr) {
            DNode* next = it->next;
            delete it;
            it = next;
        }
    }
    int get(int key, bool& found) {
        // look up the table
        unordered_map<int, DNode*>::iterator it = this->table.find(key);

        // if found, look at node's value and put the node to list head
        // if not, set found as false
        if (it == this->table.end()) {
            found = false;
            return -1;
        }
        else {
            found = true;
            DNode* target = it->second;
            if (target != this->head) {
                target->prev->next = target->next;
                if (target != this->tail) {
                    target->next->prev = target->prev;
                }
                else {
                    this->tail = target->prev;
                }

                target->prev = nullptr;
                target->next = this->head;
                this->head->prev = target;
                this->head = target;
            }
            return target->val;
        }
    }
    void put(int key, int value) {
        // check existence of the key
        unordered_map<int, DNode*>::iterator it = this->table.find(key);
        // if the key exists: update the node's value and move the node to list head
        // if the key doesn't exist: create new node and put it to list head
        if (it == this->table.end()) {
            if (this->size == this->capacity) {
                // evict the least recent used node (tail)
                DNode* nodeToGo = this->tail;
                cout << "evict node(key=" << nodeToGo->key << ")" << endl;
                this->tail = this->tail->prev;
                this->tail->next = nullptr;
                this->size -= 1;
                this->table.erase(nodeToGo->key);
                delete nodeToGo;
            }

            DNode* newNode = new DNode(key, value);
            this->table[key] = newNode;
            newNode->next = this->head;
            if (this->head != nullptr) {
                this->head->prev = newNode;
            }
            this->head = newNode;
            if (this->tail == nullptr) {
                this->tail = newNode;
            }
            this->size += 1;
        }
        else {
            DNode* target = it->second;
            target->val = value;
            if (target != this->head) {
                target->prev->next = target->next;
                if (target != this->tail) {
                    target->next->prev = target->prev;
                }
                else {
                    this->tail = target->prev;
                }

                target->prev = nullptr;
                target->next = this->head;
                this->head->prev = target;
                this->head = target;
            }
        }
    }
private:
    unordered_map<int, DNode*> table;
    DNode* head;
    DNode* tail;
    int size;
    int capacity;
};

int main(void) {

    LRUCache c(3);

    c.put(1,1);
    c.put(2,3);
    c.put(3,3);
    c.put(1,3);
    c.put(4,4); // should evict 2

    bool found = false;
    int res = -1;
    res = c.get(5, found);
    cout << "found 5: " << found << endl;

    res = c.get(3, found);
    cout << "found 3: " << found << endl;

    c.put(5, 12); // should evict 1

    return 0;
}