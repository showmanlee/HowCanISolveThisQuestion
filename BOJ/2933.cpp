// 미네랄
// https://www.acmicpc.net/problem/2933

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

// 던진 후 파괴 판정은 단순 반복문이지만, 덩어리 판정은 bfs로 처리해야 함
// 우선 매 회차마다 해당 높이에서 해당되는 방향으로 막대기를 던진 후, 미네랄을 만나면 해당 미네랄을 지운다
// 이후 bfs를 돌려 공중에 떠있는 미네랄을 판정한다 - bfs 범위 탐색 중 바닥에 있는 미네랄을 만나지 않은 경우
// bfs를 돌리며 각 덩어리에 포함된(bfs 중 만난) 미네랄 칸들을 모두 저장 - 이후 공중의 미네랄임이 확정될 경우 이를 이용해 추락 판정 처리
// 떨어지는 미네랄 덩어리의 개수는 하나임이 보장됨 - 따라서 공중 판정이 처음으로 뜨면 공중 미네랄 칸들을 복사한 후 더 이상 탐색하지 않기
// 이렇게 받은 공중 미네랄 칸들을 활용해 미네랄 추락시키기 - 공중에 있는 미네랄들을 모두 지운 후, 한 칸씩 떨어뜨려가며 바닥에 닿았는지 확인, 닿았으면 닿은 위치에 다시 미네랄 쓰기
// 이 과정을 마친 후 보드를 그려서 결과 출력