// 모래성
// https://www.acmicpc.net/problem/10711

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));
	queue<prr> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == '.') {
				board[i][j] = 0;
				q.push({ {i, j}, 0 });
			}
			else
				board[i][j] = c - '0';
		}
	}
	int res = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int len = q.front().second;
		q.pop();
		res = max(len, res);
		for (int i = 0; i < 8; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= n)
				continue;
			if (board[xx][yy] != 0) {
				board[xx][yy]--;
				if (board[xx][yy] == 0)
					q.push({ {xx, yy}, len + 1 });
			}
		}
	}
	cout << res << '\n';
}

// n*m 크기의 모래성이 파도에 맞을 때 각 칸의 모래 강도가 주변 8칸의 빈칸 수 이하일 때 무너진다고 할 때, 모래성의 형태가 변하지 않을 때까지 필요한 파도의 최소 횟수는?

// 최소를 구하라고 했으니 bfs로 접근하는 것은 맞음
// 그런데 1000*1000 보드이므로 매번 조건에 맞는 모래를 지우는 방식으로 운영하기에는 부담스러움
// 하지만 bfs 큐에 빈칸을 넣어서 bfs를 돌린다면 여느 bfs와 비슷하게 각 칸 당 1번만 탐색해서 처리 가능

// 우선 보드를 받으며 빈칸일 경우 큐에 삽입, 그렇지 않다면 해당 칸의 남은 모래 수를 보드에 저장
// 이후 큐를 돌리며 내 주변 8방향 중 모래가 있을 경우 해당 칸의 모래를 1 줄임
// 그렇게 해서 모래가 사라질 경우 해당 칸을 큐에 넣음 - 여기서 소요 시간(파도 수)도 1 올려서 넣기
// 결과값은 마지막 시점에서의 소요 시간