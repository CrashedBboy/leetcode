#include <iostream>
#include <unordered_map>
#include <list>

class LFUCache {
private:
    struct Node {
        int key;
        int value;
        Node(int k, int v) : key(k), value(v) {}
    };

    int capacity;
    int size;
    int minFreq;

    // Key to Value Mapping
    std::unordered_map<int, Node*> keyValue;

    // Key to Frequency Mapping
    std::unordered_map<int, int> keyFreq;

    // Frequency to List of Keys Mapping
    std::unordered_map<int, std::list<int>> freqList;

    // Key to Iterator Mapping for Quick Access in the List
    std::unordered_map<int, std::list<int>::iterator> keyIter;

    void updateFrequency(int key) {
        int freq = keyFreq[key];
        keyFreq[key]++;

        // Remove the key from the current frequency list
        freqList[freq].erase(keyIter[key]);

        // If the current frequency list becomes empty and it was the minimum frequency, update minFreq
        if (freqList[freq].empty() && freq == minFreq) {
            freqList.erase(freq);
            minFreq++;
        }

        // Add the key to the next frequency list
        freqList[freq + 1].push_front(key);
        keyIter[key] = freqList[freq + 1].begin();
    }

public:
    LFUCache(int cap) : capacity(cap), size(0), minFreq(0) {}

    int get(int key) {
        if (keyValue.find(key) == keyValue.end()) {
            return -1; // Key not found
        }

        // Update the frequency of the key
        updateFrequency(key);
        return keyValue[key]->value;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return; // Cannot insert into a zero-capacity cache
        }

        if (keyValue.find(key) != keyValue.end()) {
            // Key already exists, update its value and frequency
            keyValue[key]->value = value;
            updateFrequency(key);
            return;
        }

        // If the cache is full, evict the least frequently used key
        if (size >= capacity) {
            // Remove the least frequently used key from the cache
            int evictKey = freqList[minFreq].back();
            freqList[minFreq].pop_back();

            if (freqList[minFreq].empty()) {
                freqList.erase(minFreq);
            }

            keyValue.erase(evictKey);
            keyFreq.erase(evictKey);
            keyIter.erase(evictKey);
            size--;
        }

        // Add the new key-value pair
        Node* newNode = new Node(key, value);
        keyValue[key] = newNode;
        keyFreq[key] = 1;
        freqList[1].push_front(key);
        keyIter[key] = freqList[1].begin();
        minFreq = 1;
        size++;
    }

    ~LFUCache() {
        for (auto& kv : keyValue) {
            delete kv.second;
        }
    }
};

int main() {
    LFUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);
    std::cout << "Get 1: " << cache.get(1) << std::endl; // Access key 1, should print 10
    cache.put(3, 30);                                    // Evicts key 2
    std::cout << "Get 2: " << cache.get(2) << std::endl; // Should print -1 (not found)
    std::cout << "Get 3: " << cache.get(3) << std::endl; // Should print 30
    cache.put(4, 40);                                    // Evicts key 1
    std::cout << "Get 1: " << cache.get(1) << std::endl; // Should print -1 (not found)
    std::cout << "Get 3: " << cache.get(3) << std::endl; // Should print 30
    std::cout << "Get 4: " << cache.get(4) << std::endl; // Should print 40

    return 0;
}