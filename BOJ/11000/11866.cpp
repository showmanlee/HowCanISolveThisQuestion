// 요세푸스 문제 0
// https://www.acmicpc.net/problem/11866

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int n, k;
	queue<int> q;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		q.push(i);

	cout << "<";
	while (q.size() != 0) {
		for (int i = 0; i < k - 1; i++) {
			int p = q.front();
			q.pop();
			q.push(p);
		}
		int p = q.front();
		q.pop();
		cout << p;
		if (q.size() != 0)
			cout << ", ";
	}
	cout << ">" << '\n';
}

// 문제에서는 큐를 사용하라던데..?