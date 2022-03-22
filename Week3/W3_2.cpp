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

class Stack {
public:
	Node* head;
	int stackSize;
	Stack() {
		head = new Node();
		stackSize = 0;
	}

	void push(int x) {
		Node* new_node = new Node();
		new_node->data = x;
		new_node->next = head;
		head = new_node;
		stackSize++;

	}

	void pop() {
		head = head->next;
		stackSize--;
	}

	int top() {
		return head->data;
	}

	bool empty() {
		if (stackSize == 0) return true;
		else return false;
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	string s;
	while (t--) {
		cin >> s;
		Stack stack;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] - '0' > 0) {
				stack.push(s[i] - '0');
			}
			else if (s[i] == '+') {
				int x = stack.top(); stack.pop();
				int y = stack.top(); stack.pop();
				stack.push(x + y);
			}
			else if (s[i] == '-') {
				int x = stack.top(); stack.pop();
				int y = stack.top(); stack.pop();
				stack.push(y - x);
			}
			else if (s[i] == '*') {
				int x = stack.top(); stack.pop();
				int y = stack.top(); stack.pop();
				stack.push(x * y);
			}
		}
		cout << stack.top()%10 << "\n";
	}

}