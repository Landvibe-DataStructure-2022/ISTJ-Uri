#include <iostream>
#include <string>
using namespace std;

char stack[100];
int stackSize = 0;

void size() {
	cout << stackSize << "\n";
}

bool empty() {
	if (stackSize == 0) {
		return true;
	}
	return false;
}

char top() {
	if (empty()) return -1;
	else return stack[stackSize - 1];
}

void push(char x) {
	
	stack[stackSize] = x;
	stackSize++;
}

void pop() {
	if (empty()) { cout << -1 << "\n"; }
	else {
		stackSize--;
	}
}

int priority(char x) {
	if (x == '*') return 2;
	else if (x == '-' || x == '+') return 1;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	string s;
	while (t--) {
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] - '0' > 0 && s[i] -'0' <=9 ) {
				cout << s[i];
			}
			else {
				while (!empty() && (priority(top()) >= priority(s[i]))){
					cout << top();
					pop();
				}
				 push(s[i]);
			}
		}
		while (!empty()) {
			cout << top();
			pop();
		}
		cout << "\n";

	}



}