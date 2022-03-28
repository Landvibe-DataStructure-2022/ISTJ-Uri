#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node() {
		data = 0;
		next = NULL;
	}
};

class Queue {
public:
	Node* front;
	Node* rear;
	int queueSize;
	Queue() {
		front = new Node();
		rear = new Node();
		queueSize = 0;
	}

	int size() {
		return queueSize;
	}

	bool isEmpty() {
		if (queueSize == 0) {
			return true;
		}
		else return false;
	}
	
	void printFront() {
		if (isEmpty()) cout << "Empty" << "\n";
		else cout << front->data << "\n";
	}
	void printRear() {
		if (isEmpty()) cout << "Empty" << "\n";
		else cout << rear->data << "\n";
	}

	void enqueue(int value) {
		Node* new_node = new Node();
		new_node->data = value;
		if (isEmpty()) {
			front = rear = new_node;
		}
		else {
			rear->next = new_node;
			rear = new_node;
		}
		queueSize++;
	}
	void dequeue() {
		if (isEmpty()) {
			cout << "Empty" << "\n";
		}
		else {
			cout << front->data << "\n";
			front = front->next;
			queueSize--;
		}
	}

};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	Queue q;
	while (t--) {
		string s;
		cin >> s;
		if (s == "size") {
			cout << q.size() << "\n";
		}
		else if (s == "isEmpty") {
			if (q.isEmpty()) cout << "True" << "\n";
			else cout << "False" << "\n";
		}
		else if (s == "front") {
			q.printFront();
		}
		else if (s == "rear") {
			q.printRear();
		}
		else if (s == "enqueue") {
			int x; cin >> x;
			q.enqueue(x);
		}
		else if (s == "dequeue") {
			q.dequeue();
		}

	}
}