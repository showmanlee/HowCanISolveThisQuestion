// 소문난 칠공주
// https://www.acmicpc.net/problem/1941

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<vector<char>> board(5, vector<char>(5));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}
	vector<int> perm(25, 0);
	for (int i = 0; i < 7; i++) {
		perm[25 - i - 1] = 1;
	}
	int res = 0;
	do {
		vector<pr> v;
		int s = 0;
		for (int i = 0; i < 25; i++) {
			if (perm[i]) {
				pr p = {i / 5, i % 5};
				v.push_back(p);
				if (board[p.first][p.second] == 'S') {
					s++;
				}
			}
		}
		if (s < 4) {
			continue;
		}
		queue<pr> q;
		q.push(v[0]);
		vector<vector<bool>> visit(5, vector<bool>(5, false));
		visit[v[0].first][v[0].second] = true;
		int cnt = 0;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			cnt++;
			if (cnt == 7) {
				res++;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 0 || xx >= 5 || yy < 0 || yy >= 5) {
					continue;
				}
				if (perm[xx * 5 + yy] == 1 && !visit[xx][yy]) {
					q.push({xx, yy});
					visit[xx][yy] = true;
				}
			}
		}
	} while (next_permutation(perm.begin(), perm.end()));
	cout << res << '\n';
}

// S와 Y로 구성된 5x5 보드에서 서로 이어진 7개의 문자를 고를 때, 그 문자 중 S가 4개 이상인 경우 구하기