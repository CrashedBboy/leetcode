#include <utility>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class HashTable {

public:

    HashTable(int bucket_count = 11) : BUCKET_COUNT(bucket_count), element_count(0) {

        table = vector<list<pair<int, int>>>(BUCKET_COUNT, list<pair<int, int>>());
    }


    void set(int key, int value) {

        int bin_number = hash(key);

        bool exist = false;
        search(key, exist);

        if (exist) {
            for (auto& p : table[bin_number]) {

                if (p.first == key) {
                    p.second = value;
                    return;
                }
            }
        }
        else {

            table[bin_number].push_front(pair<int, int>(key, value));
            element_count += 1;
        }
    }

    int search(int key, bool& found) {

        int bin_number = hash(key);

        for (auto& p : table[bin_number]) {

            if (p.first == key) {
                found = true;
                return p.second;
            }
        }

        found = false;
        return -1;
    }

    void erase(int key) {

        int bin_number = hash(key);
        list<pair<int, int>>::iterator it = table[bin_number].begin();

        while (it != table[bin_number].end()) {

            if (it->first == key) {
                table[bin_number].erase(it);
                element_count -= 1;
                return;
            }
            it++;
        }
    }

    int size() {

        return element_count;

    }

    void clear() {

        element_count = 0;
        for (auto& li : table) {
            li.clear();
        }
    }

    void print() {

        int bin_number = 0;
        for (auto& li : table) {
            cout << "Bin number: " << bin_number << endl;
            for (auto& p : li) {
                cout << p.first << " : " << p.second << endl;
            }
            bin_number += 1;
        }
    }

private:

    int BUCKET_COUNT;

    int element_count;

    vector<list<pair<int, int>>> table;

    int hash(int key) {
        return (key % BUCKET_COUNT);
    }
};



int main() {

    HashTable map(7);

    for (int i = 0; i < 70; i++) {
        map.set(i, i);
    }

    for (int i = 0; i < 10; i++) {
        map.set(i, i+2);
    }

    map.erase(35);
    map.erase(77);

    map.print();
    cout << "Hash Table size: " << map.size() << endl;

    map.clear();
    map.print();
    cout << "Hash Table size: " << map.size() << endl;
}