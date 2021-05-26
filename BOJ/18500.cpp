// 미네랄 2
// https://www.acmicpc.net/problem/18500

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	int k;
	cin >> k;
	for (int t = 0; t < k; t++) {
		int p;
		cin >> p;
		if (t % 2 == 0) {
			for (int i = 0; i < m; i++) {
				if (board[n - p][i] == 'x') {
					board[n - p][i] = '.';
					break;
				}
			}
		}
		else {
			for (int i = m - 1; i >= 0; i--) {
				if (board[n - p][i] == 'x') {
					board[n - p][i] = '.';
					break;
				}
			}
		}
		vector<vector<bool>> visit(n, vector<bool>(m));
		queue<pr> q;
		vector<pr> clust;
		bool fall = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 'x' && !visit[i][j]) {
					visit[i][j] = true;
					q.push({ i, j });
					vector<pr> blks;
					bool ground = false;
					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						blks.push_back({ x, y });
						if (x == n - 1)
							ground = true;
						for (int l = 0; l < 4; l++) {
							int xx = x + dx[l];
							int yy = y + dy[l];
							if (xx < 0 || yy < 0 || xx >= n || yy >= m || visit[xx][yy])
								continue;
							if (board[xx][yy] == 'x') {
								visit[xx][yy] = true;
								q.push({ xx, yy });
							}
						}
					}
					if (!ground) {
						fall = true;
						clust = blks;
					}
				}
				if (fall)
					break;
			}
			if (fall)
				break;
		}
		if (fall) {
			for (pr p : clust)
				board[p.first][p.second] = '.';
			for (int i = 1; i < n; i++) {
				int verify = true;
				for (pr p : clust)
					if (p.first + i >= n || board[p.first + i][p.second] == 'x')
						verify = false;
				if (!verify) {
					for (pr p : clust)
						board[p.first + i - 1][p.second] = 'x';
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << board[i][j];
		cout << '\n';
	}
}

// 두 사람이 미네랄 덩어리를 사이에 두고 양쪽에서 막대를 던지는데, 던진 막대는 수직으로 나가고 막대가 미네랄의 한 칸에 맞으면 미네랄이 깨진다
// 그 이후 미네랄 조각이 공중에 뜨게 되면 바닥이나 다른 미네랄 덩어리에 닿을 때까지 떨어지고, 떨어진 후에는 인접한 미네랄과 합쳐진다
// 두 사람이 던진 막대기의 높이들이 주어질 때, 모든 막대를 던진 이후의 미네랄의 상태는?

// 2933 미네랄에서 추락 시 착지 판정을 맨 바닥뿐만이 아닌 덩어리 전체에 대해 판정해야 하는 버전
// 하지만 미리 전체에 대해 판정하도록 짠 덕분에, 미네랄 1 코드를 그대로 사용할 수 있음