// 격자 막기
// https://www.acmicpc.net/problem/33754

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> board(2, vector<int>(n));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	vector<int> v(n), cnt(4);
	for (int i = 0; i < n; i++) {
		v[i] = board[0][i] + board[1][i] * 2;
		cnt[v[i]]++;
	}
	if (cnt[0] > 0) {
		cout << 0 << '\n';
	} else {
		vector<vector<bool>> visit(2, vector<bool>(n));
		queue<pr> q;
		q.push({0, 0});
		visit[0][0] = true;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			int xx = x == 0 ? 1 : 0;
			int yy = y + 1;
			if (board[xx][y] == 1 && !visit[xx][y]) {
				visit[xx][y] = true;
				q.push({xx, y});
			}
			if (yy < n && board[x][yy] == 1 && !visit[x][yy]) {
				visit[x][yy] = true;
				q.push({x, yy});
			}
		}
		if (!visit[1][n - 1]) {
			cout << 0 << '\n';
		} else if (cnt[3] < n) {
			cout << 1 << '\n';
		} else {
			cout << 2 << '\n';
		}
	}
}

// 0과 1이 채워진 2*n 보드에서 1을 0으로 바꾸어 1로만 구성된 좌측상단->우측하단 경로를 없애는 최소 동작 구하기