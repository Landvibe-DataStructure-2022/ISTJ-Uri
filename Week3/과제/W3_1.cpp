#include <iostream>
#include <string>
using namespace std;

int stack[10];
int stackSize = 0;
int t;



bool empty() {
	if (stackSize == 0) {
		return true;
	}
	return false;
}

void top() {
	if (empty()) cout << -1 << "\n";
	else cout << stack[stackSize - 1] << "\n";
}

void push(int x) {
	if (stackSize >= t) cout << "FULL" << "\n";
	else {
		stack[stackSize] = x;
		stackSize++;
	}
}

void pop() {
	if (empty()) { cout << -1 << "\n"; }
	else {
		cout << stack[stackSize - 1] << "\n";
		stackSize--;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s == "empty") {
			if (empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "top") {
			top();
		}
		else if (s == "push") {
			int x;
			cin >> x;
			push(x);
		}
		else if (s == "pop") {
			pop();
		}
		
	}



}