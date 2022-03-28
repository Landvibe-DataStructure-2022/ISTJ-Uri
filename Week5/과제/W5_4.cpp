#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* prev;
	Node* next;
	Node() {
		data = 0;
		prev = NULL;
		next = NULL;
	}

};

class Iterator {
public:
	Node* v;
	Iterator(Node* v) {
		this->v = v;
	}

	Iterator* operator++() {
		v = v->next;
		return this;
	}

	Iterator* operator--() {
		v = v->prev;
		return this;
	}

};

class Sequence {
public:
	Node* head;
	Node* tail;
	int size;
	Sequence() {
		size = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}

	Node* begin() {
		return head->next;
	}

	void insert(Iterator& p, int e) {
		Node* new_node = new Node;
		new_node->data = e;

		p.v->prev->next = new_node;
		new_node->prev = p.v->prev;
		p.v->prev = new_node;
		new_node->next = p.v;
		size++;
	}

	void sum(Iterator& p) {
		int n1 = p.v->prev->data;
		int n2 = p.v->data;
		int n3 = p.v->next->data;
		int sum = (n1 * 1) + (n2 * 3) + (n3 * 1);

		cout << sum << " ";
	}
};

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		Sequence s;
		Iterator p(s.begin());
		for (int j = 0; j < N; j++) {
			int x;
			cin >> x;
			s.insert(p, x);
		}
		p = s.begin();
		for (int j = 0; j < N; j++) {
			s.sum(p);
			++p;
		}
	}
}