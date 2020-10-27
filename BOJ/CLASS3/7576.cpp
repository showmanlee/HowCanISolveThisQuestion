// 토마토
// https://www.acmicpc.net/problem/7576

#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	queue<pair<int, int>> q;
	vector<vector<int>> board(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int p;
			cin >> p;
			board[i][j] = p;
			if (p == 1)
				q.push(make_pair(i, j));
		}
	}

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	int max = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= m || yy >= n)
				continue;
			if (board[xx][yy] == 0) {
				board[xx][yy] = board[x][y] + 1;
				if (board[xx][yy] - 1 > max)
					max = board[xx][yy] - 1;
				q.push(make_pair(xx, yy));
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0) {
				cout << -1 << '\n';
				return 0;
			}
		}
	}

	cout << max << '\n';
	return 0;
}

// 토마토가 며칠만에 모두 익는가(or 모두 익지 못하는 상황인가)? - BFS로 푸는 문제
// pair = 두 객체를 하나로 묶은 클래스(비교 연산자 및 sort가 구현되어 있음), make_pair(a, b)로 생성