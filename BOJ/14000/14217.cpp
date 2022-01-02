// 그래프 탐색
// https://www.acmicpc.net/problem/14217

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
	vector<vector<bool>> board(n + 1, vector<bool>(n + 1));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = true;
		board[b][a] = true;
	}
	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			board[b][c] = board[c][b] = true;
		else
			board[b][c] = board[c][b] = false;
		vector<int> visit(n + 1, 987654321);
		queue<int> q;
		q.push(1);
		visit[1] = 0;
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			for (int i = 1; i <= n; i++) {
				if (board[p][i] && visit[i] == 987654321) {
					visit[i] = visit[p] + 1;
					q.push(i);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 987654321)
				visit[i] = -1;
			cout << visit[i] << ' ';
		}
		cout << '\n';
	}
}

// 양방향 그래프가 주어지고, 해당 그래프에서 길이 하나씩 추가되거나 없어질 때, 다른 지점에서 1번 지점으로 가는 최소 거리 출력하기

// 가중치 없는 최소 거리는 bfs - 그리고 1번 지점으로 가는 거리 = 1번 지점에서 오는 거리
// 일단 그래프는 인접행렬로 구현 - 쉽게 길을 넣고 지울 수 있도록(n = 500)
// 이후 매 길 변경 타이밍마다 bfs 돌리기 - 1번 지점부터 출발하여 각 지점의 거리 재기
// 그리고 이렇게 잰 거리를 각 회차마다 출력하기