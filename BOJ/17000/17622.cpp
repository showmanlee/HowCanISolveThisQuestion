// 타일 교체
// https://www.acmicpc.net/problem/17622

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	int res = 987654321;
	queue<pr> q;
	bool pass = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int origin = board[i][j];
			for (int r = 0; r < 6; r++) {
				board[i][j] = r;
				if ((k == 0 && board[i][j] != origin) || (k == 1 && board[i][j] == origin))
					continue;
				if (board[0][0] != 1 && board[0][0] != 3 && board[0][0] != 5)
					continue;
				if (board[n - 1][n - 1] != 0 && board[n - 1][n - 1] != 2 && board[n - 1][n - 1] != 5)
					continue;
				vector<vector<int>> visit(n, vector<int>(n, -1));
				q.push({ 0, 0 });
				visit[0][0] = 1;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					if (x == n - 1 && y == n - 1) {
						res = min(res, visit[x][y]);
						break;
					}
					for (int t = 0; t < 4; t++) {
						int xx = x + dx[t];
						int yy = y + dy[t];
						if (xx < 0 || yy < 0 || xx >= n || yy >= n)
							continue;
						if (t == 0) {
							if (board[x][y] != 2 && board[x][y] != 3 && board[x][y] != 4)
								continue;
							if (board[xx][yy] != 0 && board[xx][yy] != 1 && board[xx][yy] != 4)
								continue;
						}
						else if (t == 1) {
							if (board[x][y] != 0 && board[x][y] != 2 && board[x][y] != 5)
								continue;
							if (board[xx][yy] != 1 && board[xx][yy] != 3 && board[xx][yy] != 5)
								continue;
						}
						else if (t == 2) {
							if (board[x][y] != 0 && board[x][y] != 1 && board[x][y] != 4)
								continue;
							if (board[xx][yy] != 2 && board[xx][yy] != 3 && board[xx][yy] != 4)
								continue;
						}
						else if (t == 3) {
							if (board[x][y] != 1 && board[x][y] != 3 && board[x][y] != 5)
								continue;
							if (board[xx][yy] != 0 && board[xx][yy] != 2 && board[xx][yy] != 5)
								continue;
						}
						if (visit[xx][yy] == -1) {
							visit[xx][yy] = visit[x][y] + 1;
							q.push({ xx, yy });
						}
					}
				}
				while (!q.empty())
					q.pop();
			}
			board[i][j] = origin;
			if (k == 0) {
				pass = true;
				break;
			}
		}
		if (pass)
			break;
	}
	if (res == 987654321)
		res = -1;
	cout << res << '\n';
}

// n*n 보드에 6가지 길(┌┐└┘│─) 타일이 놓여 있을 때, 정확히 k(0 or 1)개의 타일을 바꾸어 좌측 상단 좌측 입구부터 우측 하단 우측 출구까지 이동할 수 있는가? 있다면 얼마나 걸리는가?

// k는 0 아니면 1, n은 최대 50 - 타일 하나를 바꾸는데 브루트포스로 접근 가능, 타일을 안 바꾼다면 한 번의 탐색으로도 해결 가능
// 따라서 각 칸에 대해 타일을 바꾼 경우의 수를 모두 대입함으로서 결과를 파악할 수 있음 - 단, k == 0인 경우 원래 타일에서 안 바뀐 경우에만, k == 1인 경우 바뀐 경우에만 정식 탐색 가능
// 또한 k == 0인 경우 모든 칸의 결과를 볼 필요 없이 한 번만 봐도 되므로 한번 탐색이 완료되면 추가 탐색 하지 않고 바로 결과값을 출력할 수 있도록
// 길을 따라가는 과정을 bfs를 응용 - 다만 갈림길이 없으니 탐색 자체는 일직선으로 진행됨

// 각 탐색 시작 전에 (0,0)의 좌측 방향이 뚫려있고 (n-1,n-1)의 우측 방향이 뚫려있는지 확인 - 그렇지 않으면 시작 자체가 불가능
// 이후 bfs로 길을 따라갈 때 현재 칸의 방향이 해당 방향으로 갈 수 있는지, 또 해당 칸에 있는 길이 내가 오는 방향을 받을 수 있는지 확인하고, 그렇지 않으면 다음 칸을 큐에 넣지 않기
// 만약 이 과정을 거쳐 안전하게 목적지에 왔다면 목적지까지 온 거리를 결과값에 갱신하기