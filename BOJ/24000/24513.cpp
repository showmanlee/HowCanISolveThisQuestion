// 좀비 바이러스
// https://www.acmicpc.net/problem/24513

#include <iostream> 
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, pr> prr;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m)), visit(n, vector<int>(m));
	queue<prr> q;
	queue<pr> pq;
	int resa = 0, resb = 0, resc = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1) {
				visit[i][j] = -999;
			}
			else if (board[i][j] != 0) {
				visit[i][j] = board[i][j];
				q.push({ board[i][j], {i, j} });
				board[i][j] = 0;
				if (visit[i][j] == 1) {
					resa++;
				}
				else if (visit[i][j] == 2) {
					resb++;
				}
			}
		}
	}
	while (!q.empty()) {
		int tt = q.size();
		for (int t = 0; t < tt; t++) {
			int num = q.front().first;
			int x = q.front().second.first;
			int y = q.front().second.second;
			q.pop();
			if (visit[x][y] == 3) {
				continue;
			}
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 0 || yy < 0 || xx >= n || yy >= m || board[xx][yy] == -1) {
					continue;
				}
				if (visit[xx][yy] == 0) {
					visit[xx][yy] = -num;
					q.push({ num, {xx, yy} });
					pq.push({ xx, yy });
				}
				else if (visit[xx][yy] < 0 && -visit[xx][yy] != num) {
					visit[xx][yy] = -3;
				}
			}
		}
		while (!pq.empty()) {
			int x = pq.front().first;
			int y = pq.front().second;
			pq.pop();
			if (visit[x][y] < 0) {
				visit[x][y] *= -1;
				if (visit[x][y] == 1) {
					resa++;
				}
				else if (visit[x][y] == 2) {
					resb++;
				}
				else if (visit[x][y] == 3) {
					resc++;
				}
			}
		}
	}
	cout << resa << ' ' << resb << ' ' << resc << '\n';
}

// 바이러스 차단을 막는 치료제가 있을 수 있는 n*m 형태의 마을에 1/2번 바이러스가 매 시간 상하좌우로 퍼지고, 같은 시점에 두 바이러스가 만나면 3번 바이러스가 만들어져 전염이 차단될 때, 최종적으로 각 바이러스에 감염된 집 수 구하기

// 2개의 발생원이 있는 bfs - 매 시간마다 bfs 확산 상태를 체크하고, 두 바이러스가 동시에 붙은 경우에는 3번으로 처리해줘야 함
// 따라서 매 시간마다 3번 바이러스 처리를 할 수 있도고 그 시점의 큐 크기만큼만 bfs를 처리한다
// 기본적으로 바이러스 번호와 좌표를 저장하는 bfs로 돌되, visit를 찍을 때 처음에는 음수로 표기 - 다른 바이러스가 들어간 곳에 들어갈 경우 -3으로 표기
// 이후 들어간 칸들을 돌며 음수 visit를 양수로 바꾸어 감염 확정하기 - 이후 바이러스 확산 bfs에서 3번 칸에서 시작되는 경우 탐색하지 않음