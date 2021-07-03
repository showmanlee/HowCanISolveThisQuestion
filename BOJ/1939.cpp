// 중량제한
// https://www.acmicpc.net/problem/1939

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<pr>> board(n + 1);
	int left = 0, right = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		board[a].push_back({ b, c });
		board[b].push_back({ a, c });
		right = max(right, c);
	}
	int s, g;
	cin >> s >> g;
	while (left <= right) {
		int mid = (left + right) / 2;
		vector<bool> visit(n + 1);
		queue<int> q;
		q.push(s);
		visit[s] = true;
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			if (t == g)
				break;
			for (pr& p : board[t]) {
				if (!visit[p.first] && p.second >= mid) {
					visit[p.first] = true;
					q.push(p.first);
				}
			}
		}
		if (visit[g]) 
			left = mid + 1;
		else
			right = mid - 1;
	}
	cout << right << '\n';
}

// 중량 제한이 있는 양방향 다리로 연결된 n개의 섬에서 특정 섬 사이를 이동할 때 이동할 수 있는 중량의 최댓값은?

// 중량 제한 범위가 10억까지니 이분 탐색으로 접근해야 함 - 해당 무게에서 안전하게 bfs 탐색이 가능한가?
// 다리 입력을 받아 양방향으로 놓은 뒤, left를 0, right를 다리 중량 제한의 최댓값으로 잡고 이분 탐색 bfs 시작
// 이후 bfs 순회가 가능하다면 left를 당기고, 그렇지 않다면 right를 당긴다
// 여기서 right는 현재까지 가능한 다리의 최댓값을 의미 - 즉 우리가 원하는 결과값이기도 함
// 따라서 left > right가 되어 이분 탐색이 끝나면 right를 출력해 결과 출력하기