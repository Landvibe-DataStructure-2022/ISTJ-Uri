#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;
	Node() {
		data = 0;
		next = NULL;
		prev = NULL;
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

	Node* end() {
		return tail;
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

	void erase(Iterator& p) {
		if (size == 0)
			cout << "Empty" << endl;
		else {
			Node* tmp = p.v;
			p.v->prev->next = p.v->next;
			p.v->next->prev = p.v->prev;
			size--;
			delete tmp;
		}
	}

	void print() {
		if (size == 0)
			cout << "Empty" << endl;
		else {
			Node* tmp = head->next;
			while (tmp != tail) {
				cout << tmp->data << " ";
				tmp = tmp->next;
			}
			tmp = tmp->next;
			delete tmp;
			cout << endl;
		}
	}

	void find(int x) {
		if (size == 0)
			cout << "Empty" << endl;
		else {
			Node* tmp = head->next;
			int index = 0;
			while (tmp != tail) {
				if (tmp->data == x) {
					cout << index << endl;
					return;
				}
				else {
					tmp = tmp->next;
					index++;
				}
			}
			cout << -1 << endl;
		}
	}
};


int main() {
	int M;
	cin >> M;

	Sequence s;
	string str;
	Iterator p(s.begin());
	for (int i = 0; i < M; i++) {
		cin >> str;
		if (str == "begin")
			p = s.begin();
		if (str == "end")
			p = s.end();
		if (str == "insert") {
			int x;
			cin >> x;
			s.insert(p, x);
		}
		if (str == "erase") {
			s.erase(p);
			p = s.begin();
		}
		if (str == "++") {
			++p;
		}
		if (str == "--") {
			--p;
		}
		if (str == "print") {
			s.print();
		}
		if (str == "find") {
			int x;
			cin >> x;
			s.find(x);
		}
	}
}