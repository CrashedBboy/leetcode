#include <iostream>
#include <unordered_map>
#include <list>
#include <string>

using namespace std;

template <typename T, typename U>
class LFUCache {
private:
    class Node {
    public:
        T key;
        U val;
        int freq;
        list<int>::iterator listNode;
        Node(T k, U v): key(k), val(v), freq(1) {} 
    };
public:
    LFUCache(int c) {
        if (c < 1) {
            cerr << "No capacity lower than 1" << endl;
            exit(1);
        }
        this->capacity = c;
        this->minFreq = 0;
        this->size = 0;
    }
    ~LFUCache() {
        for (auto p : this->keyToNode) {
            Node* n = p.second;
            delete n;
        }
    }
    void put(T key, U value) {
        typename unordered_map<T, Node*>::iterator it = this->keyToNode.find(key);
        if (it != this->keyToNode.end()) {
            // update the value
            Node* n = it->second;
            n->val = value;
            // update the frequency and the tracked minimum freq
            this->updateFreq(n);
        }
        else {
            if (this->size == this->capacity) {
                // time to evict
                T k = this->freqToKeyList[this->minFreq].back();
                this->freqToKeyList[this->minFreq].pop_back();
                if (this->freqToKeyList[this->minFreq].empty()) {
                    this->freqToKeyList.erase(this->minFreq);
                }
                delete this->keyToNode[k];
                this->keyToNode.erase(k);
                this->size -= 1;
                cout << "Evicted node (key=" << k << ")" << endl;
            }
            Node* newNode = new Node(key, value);
            this->keyToNode[key] = newNode;
            this->freqToKeyList[1].push_front(key);
            newNode->listNode = this->freqToKeyList[1].begin();
            this->minFreq = 1;
            this->size += 1;
        }
    }
    U get(T key, bool& found) {
        U nullAns;
        typename unordered_map<T, Node*>::iterator it = this->keyToNode.find(key);
        if (it != this->keyToNode.end()) {
            found = true;
            // update the value
            Node* n = it->second;
            // update the frequency and the tracked minimum freq
            this->updateFreq(n);
            return n->val;
        }
        else {
            found = false;
            return nullAns;
        }
    }
private:
    unordered_map<T, Node*> keyToNode;
    unordered_map<int, list<T>> freqToKeyList;
    int minFreq;
    int size;
    int capacity;
    void updateFreq(Node* n) {
        this->freqToKeyList[n->freq].erase(n->listNode);
        if (this->freqToKeyList[n->freq].empty()) {
            this->freqToKeyList.erase(n->freq);
            if (n->freq == this->minFreq) {
                this->minFreq += 1;
            }
        }
        n->freq += 1;
        this->freqToKeyList[n->freq].push_front(n->key);
        n->listNode = this->freqToKeyList[n->freq].begin();
    }
};


int main (void) {

    bool found = false;

    LFUCache<int, string> c1 (3);
    string res1;
    c1.put(1, "one");
    c1.put(2, "two");
    c1.put(3, "three");
    res1 = c1.get(2, found);
    if (found == false || res1 != "two") {
        cout << "test 1 failed" << endl;
    }
    c1.put(1, "one one");
    c1.put(4, "four"); // 3 should be evicted
    res1 = c1.get(3, found);
    if (found) {
        cout << "test 2 failed" << endl;
    }

    cout << "all tests passed" << endl;

    return 0;
}