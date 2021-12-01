// 와드
// https://www.acmicpc.net/problem/23747

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[5] = { -1, 0, 1, 0, 0};
int dy[5] = { 0, 1, 0, -1, 0 };

int dir(char c) {
	if (c == 'U') {
		return 0;
	}
	if (c == 'R') {
		return 1;
	}
	if (c == 'D') {
		return 2;
	}
	if (c == 'L') {
		return 3;
	}
	return 4;
}


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n + 2, vector<char>(m + 2, '.'));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	int x, y;
	cin >> x >> y;
	string commands;
	cin >> commands;
	vector<vector<int>> visit(n + 2, vector<int>(m + 2));
	for (int i = 0; i < 5; i++) {
		visit[x + dx[i]][y + dy[i]] = 1;
	}
 	for (char c : commands) {
		if (c == 'W') {
			queue<pr> q;
			q.push({ x, y });
			visit[x][y] = 2;
			while (!q.empty()) {
				int _x = q.front().first;
				int _y = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int xx = _x + dx[i];
					int yy = _y + dy[i];
					if (board[_x][_y] == board[xx][yy] && visit[xx][yy] != 2) {
						visit[xx][yy] = 2;
						q.push({ xx, yy });
					}
				}
			}
		}
		else {
			for (int i = 0; i < 5; i++) {
				if (visit[x + dx[i]][y + dy[i]] == 1) {
					visit[x + dx[i]][y + dy[i]] = 0;
				}
			}
			x += dx[dir(c)];
			y += dy[dir(c)];
			for (int i = 0; i < 5; i++) {
				if (visit[x + dx[i]][y + dy[i]] == 0) {
					visit[x + dx[i]][y + dy[i]] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << (visit[i][j] == 0 ? '#' : '.');
		}
		cout << '\n';
	}
}

// 각 칸마다 알파벳으로 영역이 주어진 n*m 보드에서 시작점에서 출발해 이동하거나 와드를 박는 일련의 과정을 수행할 때, 최종적으로 확보한 시야는?
// 시야는 기본적으로 나의 위치와 상하좌우 한 칸이 보이고, 와드를 박으면 해당 칸과 연결된 같은 영역에 시야가 밝혀진다

// 우선 입력할 것들을 받는다 - board와 visit는 조건문 최소화를 위해 테두리 한 칸씩 주고 시작하기
// visit의 경우 플레이어 시야로 받은 것은 1, 와드 시야로 받은 것은 2로 표시 - 두 시야가 서로 겹치지 않도록
// 이후 명령을 수행하며 이동 명령의 경우 해당 칸으로 가기 전 플레이어 시야를 지우고, 이동 후 플레이어 시야를 다시 채운다
// 와드 명령의 경우 해당 칸에서 영역 탐색 bfs를 돌리며 만나는 칸을 모두 2로 채운다
// 이렇게 채운 시야들을 출력하기