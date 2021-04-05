// 도키도키 간식드리미
// https://www.acmicpc.net/problem/12789

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	queue<int> q;
	stack<int> s;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		q.push(p);
	}
	int now = 1;
	while (!q.empty()) {
		if (q.front() != now) 
			s.push(q.front());
		else 
			now++;
		q.pop();
		while (!s.empty() && s.top() == now) {
			now++;
			s.pop();
		}
	}
	while (!s.empty() && s.top() == now) {
		now++;
		s.pop();
	}
	cout << (now > n ? "Nice" : "Sad") << '\n';
}

// 번호가 섞인 채 한 줄로 서있는 사람들을 스택을 이용해 번호 순서대로 간식을 줄 수 있는가?
// 일단 큐가 빌 때까지 큐 앞에 있는 사람이 현재 번호표를 받아야 하는 번호인지 확인하고 그렇다면 빼고, 그렇지 않다면 큐에 넣는다
// 이후 스택을 확인해 번호표를 받아야 하는 사람이 맨 앞에 있다면 그렇지 않을 때까지 스택에 있는 사람을 뺀다
// 큐가 다 비면 위의 과정을 한 번 더 수행해, 마지막 사람까지 받게 되면 성공, 아니면 실패 판정