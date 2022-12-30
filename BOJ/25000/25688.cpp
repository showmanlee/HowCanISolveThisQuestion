// 빠른 무작위 숫자 탐색
// https://www.acmicpc.net/problem/25688

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
	vector<vector<vector<int>>> visit(5, vector<vector<int>>(5, vector<int>(128, -1)));
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
		if (cur == 0b1111110) {
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
				if (board[xx][yy] != 0 && (cur | (1 << (board[xx][yy])))) {
					int ncur = cur | 1 << (board[xx][yy]);
					visit[xx][yy][ncur] = visit[xx][yy][cur];
					q.push({{xx, yy}, ncur});
				} else {
					q.push({{xx, yy}, cur});
				}
			}
		}
	}
	cout << res << '\n';
}

// 5x5 보드에 출발지부터 1~6을 순서 상관 없이 모두 밟는 최소 거리는?

// 25513과 같은 문제 - 근데 이번에는 밟는 순서 상관 없음
// 말인즉 visit 배열 관리를 숫자 순서가 아닌 개별 숫자 도달 여부로 잡아줘야 함
// 따라서 비트마스킹으로 관리, 최종적으로 1111110이 되어 모든 숫자를 밟게 되면 탈출하도록