// 빠른 오름차순 숫자 탐색
// https://www.acmicpc.net/problem/25513

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<vector<int>> board(5, vector<int>(5));
	vector<vector<vector<int>>> visit(5, vector<vector<int>>(5, vector<int>(7, -1)));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}
	int r, c;
	cin >> r >> c;
	visit[r][c][0] = 0;
	queue<prr> q;
	q.push({{r, c}, 0});
	int res = -1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cur = q.front().second;
		q.pop();
		if (cur == 6) {
			res = visit[x][y][cur];
			break;
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx > 4 || yy > 4 || board[xx][yy] == -1) {
				continue;
			}
			if (visit[xx][yy][cur] == -1) {
				visit[xx][yy][cur] = visit[x][y][cur] + 1;
				if (board[xx][yy] == cur + 1) {
					visit[xx][yy][cur + 1] = visit[xx][yy][cur];
					q.push({{xx, yy}, cur + 1});
				} else {
					q.push({{xx, yy}, cur});
				}
			}
		}
	}
	cout << res << '\n';
}

// 5x5 보드에 출발지부터 1~6을 차례대로 밟는 최소 거리는?

// 최소 거리는 bfs - 그런데 마지막으로 밟은 숫자가 어디인지도 기억해야 함
// 시작은 출발지의 0번 슬롯 -> 여기서 1번을 찾을 때까지 0번 슬롯에서 bfs를 돌림
// 만약 1번을 찾았다면 해당 위치에서 1번 슬롯으로 옮겨서 bfs -> 이 과정을 6번 슬롯 도달할 때까지 반복
// 6번 슬롯에 도달하면 지금까지의 거리를 정답으로 출력