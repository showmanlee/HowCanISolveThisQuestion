// 4연산
// https://www.acmicpc.net/problem/14395

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long s, t;
	cin >> s >> t;
	map<long long, int> visit;
	map<long long, long long> prev;
	map<long long, char> ops;
	visit[s] = 0;
	prev[s] = -1;
	ops[s] = ' ';
	queue<long long> q;
	q.push(s);
	while (!q.empty()) {
		long long p = q.front();
		q.pop();
		if (p == t)
			break;
		if (p * p >= 0 && p * p <= 1000000000 && visit.count(p * p) == 0) {
			visit[p * p] = visit[p] + 1;
			prev[p * p] = p;
			ops[p * p] = '*';
			q.push(p * p);
		}
		if (p + p >= 0 && p + p <= 1000000000 && visit.count(p + p) == 0) {
			visit[p + p] = visit[p] + 1;
			prev[p + p] = p;
			ops[p + p] = '+';
			q.push(p + p);
		}
		if (p - p >= 0 && p - p <= 1000000000 && visit.count(p - p) == 0) {
			visit[p - p] = visit[p] + 1;
			prev[p - p] = p;
			ops[p - p] = '-';
			q.push(p - p);
		}
		if (p != 0 && p / p >= 0 && p / p <= 1000000000 && visit.count(p / p) == 0) {
			visit[p / p] = visit[p] + 1;
			prev[p / p] = p;
			ops[p / p] = '/';
			q.push(p / p);
		}
	}
	string res;
	long long idx = t;
	if (s == t)
		res = "0";
	else if (visit.count(t) == 0)
		res = "-1";
	else {
		while (ops[idx] != ' ') {
			res += ops[idx];
			idx = prev[idx];
		}
		reverse(res.begin(), res.end());
	}
	cout << res << '\n';
}

// 현재 수끼리 곱하고 더하고 빼고 나누는 과정만으로 어떤 정수를 다른 수로 바꿀 수 있는가? 있다면 어떻게 연산해야 하는가?

// 범위가 10억까지지만 bfs + map 수준에서 처리 가능(커지는 폭이 크기 때문에)
// 사용할 수 있는 범위는 0부터 10억 - 그 이상으로 도달하면 최소 거리를 만족하지 않음이 보장됨(10억 범위로 복귀하는데 연산자를 써야하니까)
// 따라서 이 원리를 이용해 연산을 통한 bfs를 돌려준다 - 그러면서 연산자 출력을 위해 지난 노드와 그 노드와의 연산에서 쓰인 연산자를 기록
// bfs 탐색을 마치면 두 가지 여부를 확인 - s와 t가 같으면 0, visit에 t가 찍히지 않았다면 1
// 둘 다 아니라면 prev를 통해 타고 올라가면서 연산자를 모으고 반전하여 출력하기