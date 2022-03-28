#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
	int queue[100]{};
	int frontIndex;
	int rearIndex;
	int queueSize;

public:
	Queue() {
		frontIndex = 0;
		rearIndex = -1;
		queueSize = 0;
	}

	void enqueue(int value) {
		rearIndex++;
		queue[rearIndex] = value;
		queueSize++;
	}

	void dequeue() {
		frontIndex++;
		queueSize--;
	}

	int front() {
		return queue[frontIndex];
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		Queue player1;
		Queue player2;
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			player1.enqueue(x);
		}
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			player2.enqueue(x);
		}


		int remainHpOfP1 = 0;
		int remainHpOfP2 = 0;
		int scoreOfP1 = 0;
		int scoreOfP2 = 0;

		for (int i = 0; i < n; i++) {
			int cardOfP1 = player1.front() + remainHpOfP1;
			player1.dequeue();
			int cardOfP2 = player2.front() + remainHpOfP2;
			player2.dequeue();

			if (cardOfP1 > cardOfP2) {
				remainHpOfP1 = cardOfP1 - cardOfP2;
				remainHpOfP2 = 0;
				scoreOfP1++;
			}
			else if (cardOfP2 > cardOfP1) {
				remainHpOfP2 = cardOfP2 - cardOfP1;
				remainHpOfP1 = 0;
				scoreOfP2++;
			}
			else {
				remainHpOfP1 = remainHpOfP2 = 0;
			}
			cout << "Round" << i + 1 << " " << scoreOfP1 << ":" << scoreOfP2 << "\n";
		}

		if (scoreOfP1 > scoreOfP2) {
			cout << "Winner P1" << "\n";
		}
		else if (scoreOfP2 > scoreOfP1) {
			cout << "Winner P2" << "\n";
		}
		else {
			cout << "Draw" << "\n";
		}
	}
}
