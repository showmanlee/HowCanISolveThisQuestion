// 카드1
// https://www.acmicpc.net/problem/2161

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++)
		q.push(i);
	while (q.size() > 1) {
		cout << q.front() << ' ';
		q.pop();
		int t = q.front();
		q.pop();
		q.push(t);
	}
	cout << q.front() << '\n';
}

// 1부터 n까지의 카드가 쌓여있는 카드 더미에서 가장 위의 카드를 버리고, 그 다음 위의 카드를 아래로 옮길 때, 카드를 버리는 순서와 남는 카드는?
// 큐 선에서 처리 가능 - 위에서는 버리고, 아래에서 계속 넣기 때문