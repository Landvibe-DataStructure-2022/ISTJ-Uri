#include <iostream>
#include <string>
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

class List {
public:
	Node* head;
	Node* tail;
	int list_size;
	List() {
		head = new Node();
		tail = new Node();
		list_size = 0;
	}

	void Print() {
		if (list_size == 0) {
			cout << "empty" << "\n";
			return;

		}
		Node* cur_node = head;
		while (cur_node != tail) {
			cout << cur_node->data << " ";
			cur_node = cur_node->next;
		}
		cout << tail->data << "\n";
	}

	void Append(int x) {
		Node* new_node = new Node();
		new_node->data = x;
		if (list_size == 0) {
			head = new_node;
			tail = head;
		}
		if (list_size == 1) {
			head->next = new_node;
			tail = new_node;
		}
		else {
			tail->next = new_node;
			tail = new_node;
		}
		list_size++;
		Print();
	}

	void Delete(int index) {
		if (list_size == 0 || list_size <= index) {
			cout << -1 << "\n";
			return;
		}
		if (index == 0 && list_size == 1) {
			cout << head->data << "\n";
			head->data = 0;
			head->next = NULL;
			tail = head;
		} 
		else if (list_size - 1 == index) {
			cout << tail->data << "\n";
			Node* cur_node = head;
			while (cur_node->next != tail) {
				cur_node = cur_node->next;
			}
			tail = cur_node;
		}
		else if (index == 0) {
			cout << head->data << "\n";
			head = head->next;
		}
		else {
			Node* cur_node = head;
			for (int i = 0; i < index-1; i++) {
				cur_node = cur_node->next;
			}
			int tmp = cur_node->next->data;
			cur_node->next = cur_node->next->next;
			cout << tmp << "\n";
		}
		list_size--;
	}

	void Insert(int index, int x) {
		if (index > list_size) {
			cout << "Index Error" << "\n";
			return;
		}
		Node* new_node = new Node();
		new_node->data = x;
		if (index == 0 && list_size == 0) {
			head = new_node;
		}
		else if (list_size == index) {
			tail->next = new_node;
			tail = new_node;
		}
		else if (index == 0) {
			new_node->next = head;
			head = new_node;
		}
		else {
			Node* cur_node = head;
			for (int i = 0; i < index - 1; i++) {
				cur_node = cur_node->next;
			}
			new_node->next = cur_node->next;
			cur_node->next = new_node;
		}
		list_size++;
		Print();
	}

	void Min() {
		if (list_size == 0) {
			cout << "empty" << "\n";
			return;

		}
		Node* cur_node = head;
		int min = head->data;
		while (cur_node != tail) {
			min = min >= cur_node->data ? cur_node->data : min;
			cur_node = cur_node->next;
		}
		min = min >= tail->data ? tail->data : min;
		cout << min << "\n";
	}
};


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int m;
	cin >> m;
	string s;

	List l;

	while (m--) {
		cin >> s;
		if (s == "Print") {
			l.Print();
		}
		else if (s == "Append") {
			int x; cin >> x;
			l.Append(x);
		}
		else if (s == "Delete") {
			int i; cin >> i;
			l.Delete(i);
		}
		else if (s == "Insert") {
			int i, x;
			cin >> i >> x;
			l.Insert(i, x);
		}
		else if( s=="Min"){
			l.Min();
		}
	}

}