// 덱
// https://www.acmicpc.net/problem/10866

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	vector<int> deque;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "push_front") {
			int x;
			cin >> x;
			deque.insert(deque.begin(), x);
		}
		else if (command == "push_back") {
			int x;
			cin >> x;
			deque.push_back(x);
		}
		else if (command == "pop_front") {
			if (deque.empty()) {
				cout << -1 << endl;
				continue;
			}
			cout << *deque.begin() << endl;
			deque.erase(deque.begin());
		}
		else if (command == "pop_back") {
			if (deque.empty()) {
				cout << -1 << endl;
				continue;
			}
			cout << *(deque.end() - 1) << endl;
			deque.pop_back();
		}
		else if (command == "size") {
			cout << deque.size() << endl;
		}
		else if (command == "empty") {
			cout << (deque.empty() ? "1" : "0") << endl;
		}
		else if (command == "front") {
			if (deque.empty()) {
				cout << -1 << endl;
				continue;
			}
			cout << *deque.begin() << endl;
		}
		else if (command == "back") {
			if (deque.empty()) {
				cout << -1 << endl;
				continue;
			}
			cout << *(deque.end() - 1) << endl;
		}
	}
}

// 지금까지 '데큐'로 읽었던 내 자신에게 반성