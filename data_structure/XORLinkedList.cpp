#include <iostream>
#include <vector>

using namespace std;

class Node {

public:
	int val;
	Node* npx;
	Node(int x) : val(x), npx(nullptr) {}

	static Node* XOR(Node* a, Node* b) {
		return (Node*)(reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
	}
};

class List {

public:
	Node* head;

	void insert(int x) {
		Node* n = new Node(x);
		n->npx = head; // NULL XOR A == A

		if (head != nullptr) {
			head->npx = Node::XOR(n, head->npx);
		}
		
		head = n;
	}

	void print() {

		Node* prev = nullptr;
		Node* current = head;
		Node* next = nullptr;
		while (current != nullptr) {
			cout << current->val << ",";

			next = Node::XOR(prev, current->npx);
			prev = current;
			current = next;
		}
	}
};

int main() {

	vector<int> inputs = {2, 3, 4, 6, 7};

	List* list = new List();

	for (auto& n : inputs) {
		list->insert(n);
	}

	list->print();

	return 0;
}