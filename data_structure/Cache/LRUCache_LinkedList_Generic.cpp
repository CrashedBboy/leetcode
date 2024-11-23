#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// doubly-linked list
template <typename T, typename U>
class DNode {
public:
    DNode<T, U>* prev;
    DNode<T, U>* next;
    T key;
    U val;
    DNode(T key, U val): prev(nullptr), next(nullptr), key(key), val(val) {}
};

// LRU Cache
template <typename T, typename U>
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
        DNode<T, U>* it = this->head;
        while (it != nullptr) {
            DNode<T, U>* next = it->next;
            delete it;
            it = next;
        }
    }
    U get(T key, bool& found) {
        // look up the table
        
        typename unordered_map<T, DNode<T, U>*>::iterator it = this->table.find(key);

        // if found, look at node's value and put the node to list head
        // if not, set found as false
        if (it == this->table.end()) {
            found = false;
            return (U)0;
        }
        else {
            found = true;
            DNode<T, U>* target = it->second;
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
    void put(T key, U value) {
        // check existence of the key
        typename unordered_map<T, DNode<T, U>*>::iterator it = this->table.find(key);
        // if the key exists: update the node's value and move the node to list head
        // if the key doesn't exist: create new node and put it to list head
        if (it == this->table.end()) {
            if (this->size == this->capacity) {
                // evict the least recent used node (tail)
                DNode<T, U>* nodeToGo = this->tail;
                cout << "evict node(key=" << nodeToGo->key << ")" << endl;
                this->tail = this->tail->prev;
                this->tail->next = nullptr;
                this->size -= 1;
                this->table.erase(nodeToGo->key);
                delete nodeToGo;
            }

            DNode<T, U>* newNode = new DNode<T, U>(key, value);
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
            DNode<T, U>* target = it->second;
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
    unordered_map<T, DNode<T, U>*> table;
    DNode<T, U>* head;
    DNode<T, U>* tail;
    int size;
    int capacity;
};

int main(void) {

    LRUCache<int, int> c(3);

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

    LRUCache<char, string> c2(3);

    c2.put('a', "Alice");
    c2.put('b', "Bob");
    c2.put('c', "Cat");
    c2.put('d', "Duck"); // should evict 'a'
    string res2;
    res2 = c2.get('b', found);
    cout << "found b: " << found << endl; // should be 1
    c2.put('e', "eip"); // should evict 'c'

    return 0;
}