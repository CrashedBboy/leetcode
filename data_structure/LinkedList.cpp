#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
        Node* next;
        int data;
        Node (int value): next {NULL}, data {0} {
            data = value;
        }
};

class LinkedList {

    public:

        Node* root;

        LinkedList (): root {NULL} { }

        LinkedList (vector<int> nums) { 

            if (nums.empty()) {
                root = NULL;
                return;
            }

            root = new Node(nums[0]);
            Node* current = root;
            for (int i = 1; i < nums.size(); i++) {
                Node* node = new Node(nums[i]);
                current->next = node;
                current = node;
            }
        }

        void print () { 

            Node* current = root;
            while (current != NULL) {
                cout << current->data << "->";
                current = current->next;
            }
            cout << "NULL" << endl;
        }

        Node* insert (int index, int value) { 

            // case 1: root is NULL
            // case 2: size = 1
            // case 3: size = 2

            int currentIndex = 0;
            Node* currentNode = root;
            Node* previousNode = NULL;
            while (currentIndex < index && currentNode != NULL) {
                previousNode = currentNode;
                currentNode = currentNode->next;
                currentIndex += 1;
            }

            if (currentIndex == index) {

                Node* newNode = new Node(value);

                if (previousNode != NULL) {

                    if (currentNode == NULL) {
                        previousNode->next = newNode;
                    }
                    else {
                        newNode->next = currentNode;
                        previousNode->next = newNode;
                    }
                }
                else {
                    // the list is empty
                    if (currentNode == NULL) {
                        root = newNode;
                    }
                    else {
                        newNode->next = currentNode;
                        root = newNode;
                    }
                    
                }
                return newNode;
            }

            // target index is larger than list size
            return NULL;
        }

        void erase (int index) {
            int currentIndex = 0;
            Node* currentNode = root;
            Node* previousNode = NULL;
            while (currentIndex < index && currentNode != NULL) {
                previousNode = currentNode;
                currentNode = currentNode->next;
                currentIndex += 1;
            }

            if (currentIndex == index && currentNode != NULL) {

                // if the target node is in the middle of list
                if (currentNode->next != NULL) {

                    // current node is not root
                    if (previousNode != NULL) {
                        previousNode->next = currentNode->next;
                    }
                    else {
                        root = currentNode->next;
                    }
                } else {
                    // current node is not root
                    if (previousNode != NULL) {
                        previousNode->next = NULL;
                    }
                    else {
                        root = NULL;
                    }
                }
                delete currentNode;
            }
            else {
                return;
            }
        }

        Node* pushFront (int value) {

            Node* newNode = new Node(value);

            if (root == NULL) {
                root = newNode;
            }
            else {
                newNode->next = root;
                root = newNode;
            }

            return root;
        }

        Node* pushBack (int value) {

            Node* newNode = new Node(value);

            Node* currentNode = root;

            if (currentNode == NULL) {
                root = newNode;
                return root;
            }

            while (currentNode->next != NULL) {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
            return newNode;
        } 

        void clear () {

            // delete from the beginning to the end
            Node* currentNode = root;
            Node* previousNode = NULL;
            while (currentNode != NULL) {
                previousNode = currentNode;
                currentNode = currentNode->next;
                delete previousNode;
            }

            root = NULL;
        }

        void reverse () {

            if (root == NULL) {
                return;
            }

            Node* previousNode = NULL;
            Node* currentNode = root;
            Node* tmp;
            while (currentNode != NULL) {

                // to REVERSE A-B-C, current at B
                // 1. tmp = C
                // 2. B.next = A
                // 3. previous = B
                // 4. current = tmp = C

                tmp = currentNode->next;
                currentNode->next = previousNode;
                previousNode = currentNode;
                currentNode = tmp;
            }

            root = previousNode;
        }
};


int main () {

    vector<int> nums = {};

    LinkedList* list = new LinkedList(nums);

    list->print();

    Node* newNode;
    newNode = list->insert(1, 12); // insert on non-existed position
    newNode = list->insert(0, 13); // push back
    newNode = list->insert(1, 2); // push back
    newNode = list->insert(1, 5); // insert on the middle
    newNode = list->insert(0, 8); // insert on the root
    list->print();

    list->erase(0);
    list->erase(1);
    list->erase(99);
    list->erase(1);
    list->print();

    delete list;

    list = new LinkedList();
    list->pushBack(12);
    list->pushBack(16);
    list->pushBack(20);
    list->pushFront(1);
    list->pushFront(3);
    list->pushFront(5);

    list->print();

    list->reverse();

    list->print();

    return 0;
}