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
			p.v->prev->next = p.v->next;
			p.v->next->prev = p.v->prev;
			size--;
		}
	}

	void reversePrint() {
		if (size == 0)
			cout << "Empty" << endl;
		else {
			Node* cur_node = tail->prev;
			while (cur_node != head) {
				cout << cur_node->data << " ";
				cur_node = cur_node->prev;
			}
			cout << endl;
		}
	}

	void find(int e) {
		if (size == 0)
			cout << "Empty" << endl;
		else {
			Node* cur_node = head->next;
			int index = 0;
			while (cur_node != tail) {
				if (cur_node->data == e) {
					cout << index << endl;
					return;
				}
				index++;
				cur_node = cur_node->next;
			}
			cout << -1 << endl;
		}
	}
};

int main() {
	int M;
	cin >> M;

	Sequence s;
	Iterator p(s.begin());
	string str;
	for (int i = 0; i < M; i++) {
		cin >> str;
		if (str == "begin") {
			p = s.begin();
		}
		if (str == "end") {
			p = s.end();
		}
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
		if (str == "reversePrint") {
			s.reversePrint();
		}
		if (str == "find") {
			int x;
			cin >> x;
			s.find(x);
		}
	}
}