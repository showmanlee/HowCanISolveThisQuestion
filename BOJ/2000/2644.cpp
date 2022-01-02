// 촌수계산
// https://www.acmicpc.net/problem/2644

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	int n, a, b, m;
	cin >> n;
	vector<vector<bool>> family(n + 1, vector<bool>(n + 1));
	cin >> a >> b;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int p, q;
		cin >> p >> q;
		family[p][q] = true;
		family[q][p] = true;
	}
	int res = 0;
	vector<bool> visit(n + 1);
	queue<pr> q;
	q.push({ a, 0 });
	visit[a] = true;
	while (!q.empty()) {
		int p = q.front().first;
		int r = q.front().second;
		if (p == b) {
			res = r;
			break;
		}
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (family[p][i] && !visit[i]) {
				visit[i] = true;
				q.push({ i, r + 1 });
			}
		}
	}
	if (res == 0)
		res = -1;
	cout << res << '\n';
}

// 두 사람의 촌수 관계 구하기
// 형제간 2촌이 되는 것은 사실 형-부모-동생 순으로 올라갔다 내려와서 2촌이 되는 것
// 따라서 선이 연결되어 있으면 1촌씩 추가된다 보면 됨
// 가족 멤버 수가 100명이니 인접행렬 그래프를 만들어보자 - 양쪽으로 간선을 넣어줘야 함
// 그리고나서 BFS 문제로s