// 점프 점프
// https://www.acmicpc.net/problem/14248

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, s;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	cin >> s;

	vector<bool> visit(n + 1);
	visit[s] = true;
	int res = 1;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (p - v[p] > 0) {
			if (!visit[p - v[p]]) {
				visit[p - v[p]] = true;
				res++;
				q.push(p - v[p]);
			}
		}
		if (p + v[p] <= n) {
			if (!visit[p + v[p]]) {
				visit[p + v[p]] = true;
				res++;
				q.push(p + v[p]);
			}
		}
	}
	cout << res << '\n';
}

// 1차원 배열에 왼쪽이나 오른쪽으로 이동할 수 있는 숫자가 있고 배열 밖으로 벗어날 수 없을 때, 출발지에서 도달할 수 있는 칸 수 구하기

// 1차원 bfs - 그런데 각 칸마다 움직일 수 있는 위치가 다른
// 이를 고려하여 bfs를 수행한다