// 확장 게임
// https://www.acmicpc.net/problem/16920

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, pr> prrr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, p;
	cin >> n >> m >> p;
	vector<int> moves(p + 1);
	for (int i = 1; i <= p; i++)
		cin >> moves[i];
	vector<vector<char>> board(n, vector<char>(m));
	priority_queue<prrr> pq, npq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] != '.' && board[i][j] != '#') {
				int t = board[i][j] - '0';
				pq.push({ {-t, moves[t]}, {i, j} });
			}
		}
	}
	while (!pq.empty()) {
		int num = -pq.top().first.first;
		int left = pq.top().first.second;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m)
				continue;
			if (board[xx][yy] == '.') {
				board[xx][yy] = num + '0';
				if (left - 1 == 0)
					npq.push({ {-num, moves[num]}, {xx, yy} });
				else
					pq.push({ {-num, left - 1}, {xx, yy} });
			}
		}
		if (pq.empty()) {
			while (!npq.empty()) {
				pq.push(npq.top());
				npq.pop();
			}
		}
	}
	vector<int> res(p + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != '.' && board[i][j] != '#') {
				res[board[i][j] - '0']++;
			}
		}
	}
	for (int i = 1; i <= p; i++)
		cout << res[i] << ' ';
	cout << '\n';
}

// n*m 보드에 p명의 플레이어가 각자의 성(들)을 놓고, 매 턴 자신의 확장 칸만큼 성을 확장할 때, 최종적으로 플레이어들이 세울 수 있는 칸은?

// 여러 명이 순차적으로 진행하는 bfs 확장 - 다만 모두가 1칸씩 확장하는 것은 아님
// 어떤 플레이어가 2칸 이상 확장할 수 있을 때, 그 미만에 도달할 수 있는 칸들도 모두 차지할 수 있음 - 2칸 확장하는데 중간에 벽이 있는 경우 그 방향으로 확장 불가
// 그러니까 말이 조금 꼬였을 뿐, 일반적인 bfs 확장인 것
// 이 상황에서 각 플레이어별로 큐를 운영하지 않는다면 일반 큐를 사용해서는 안됨 - 처음에 칸을 넣을 때나 확장할 때 플레이어 차례가 섞일 수 있음
// 따라서 우선순위 큐로 bfs 큐를 구현 - 플레이어(-), 이동 횟수, 좌표 순으로
// 또한 다음 턴을 위한 대기용 우선순위 큐로 구현 - 현재 탐색 중 남은 이동 횟수를 다 썼다면 초기 이동 횟수를 대기용 큐에 넣고, 원래 큐가 비면 대기용 큐의 내용을 옮겨담기
// 보드는 visit의 역할도 수행하도록 하고, 최종적으로 탐색을 마쳤을 때 보드를 순회하며 칸들을 셀 수 있도록 처리