#include <iostream>
#include <string>
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

	void insert(Iterator& p, int x) {
		Node* new_node = new Node;
		new_node->data = x;

		p.v->prev->next = new_node;
		new_node->prev = p.v->prev;
		p.v->prev = new_node;
		new_node->next = p.v;

		size++;
	}

	void Max(Iterator& p) {
		int num1 = p.v->prev->data;
		int num2 = p.v->data;
		int num3 = p.v->next->data;
		if (num1 > num2 && num1 > num3) {
			cout << num1 << " ";
		}
		else if (num2 > num3 && num2 > num1) {
			cout << num2 << " ";
		}
		else if (num3 > num1 && num3 > num2) {
			cout << num3 << " ";
		}
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
			s.Max(p);
			++p;
		}
		cout << endl;
	}
}