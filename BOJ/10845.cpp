// 큐
// https://www.acmicpc.net/problem/10845

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void) {
	queue<int> q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string p;
		cin >> p;
		if (p == "push") {
			int i;
			cin >> i;
			q.push(i);
		}
		else if (p == "pop") {
			if (q.empty())
				cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (p == "size")
			cout << q.size() << endl;
		else if (p == "empty")
			cout << (q.empty() ? 1 : 0) << endl;
		else if (p == "front") {
			if (q.empty())
				cout << -1 << endl;
			else 
				cout << q.front() << endl;
		}
		else if (p == "back") {
			if (q.empty())
				cout << -1 << endl;
			else
				cout << q.back() << endl;
		}
	}
}
// 있는 거는 잘 써먹자