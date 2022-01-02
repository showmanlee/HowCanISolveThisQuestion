// 달이 차오른다, 가자.
// https://www.acmicpc.net/problem/1194

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, pr> prrr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	vector<vector<vector<bool>>> visit(n, vector<vector<bool>>(m, vector<bool>(64)));
	int sx, sy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == '0') {
				sx = i;
				sy = j;
				board[i][j] = '.';
			}
		}
	}
	queue<prrr> q;
	visit[sx][sy][0] == true;
	q.push({ {sx, sy}, {0, 0} });
	int res = -1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int keys = q.front().second.first;
		int dist = q.front().second.second;
		q.pop();
		if (board[x][y] == '1') {
			res = dist;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m || visit[xx][yy][keys] || board[xx][yy] == '#')
				continue;
			if (board[xx][yy] == '.' || board[xx][yy] == '1') {
				visit[xx][yy][keys] = true;
				q.push({ {xx, yy}, {keys, dist + 1} });
			}
			else if (board[xx][yy] >= 'a' && board[xx][yy] <= 'f') {
				int nkeys = keys | (1 << (board[xx][yy] - 'a'));
				if (!visit[xx][yy][nkeys]) {
					visit[xx][yy][nkeys] = visit[xx][yy][keys] = true;
					q.push({ {xx, yy}, {nkeys, dist + 1} });
				}
			}
			else if (board[xx][yy] >= 'A' && board[xx][yy] <= 'F') {
				if ((keys >> (board[xx][yy] - 'A')) % 2 == 1) {
					visit[xx][yy][keys] = true;
					q.push({ {xx, yy}, {keys, dist + 1} });
				}
			}
		}
	}
	cout << res << '\n';
}

// 대응하는 열쇠를 찾아야 열 수 있는 문이 있는 미로에서 탈출할 수 있는가? 있다면 최소 시간은 얼마인가?
// 같은 종류의 열쇠나 문이 여러 개 있을 수 있다 - 또한 출구도 여러 개가 있을 수 있다
// 최소 경로를 찾는 문제니 bfs 문제고, 대응되는 열쇠를 찾아야 하니 3차원 visit로 접근
// 여기서 visit는 [n][m][64]가 되어야 함 - 2^6가지 열쇠 소지 경우의 수
// 따라서 열쇠 소지의 개수는 비트마스킹으로 표현 - (b | 1 << t)로 삽입, ((b >> t) % 2)로 검색

// 벽이 아닌 한 칸의 형태는 네 가지 - 빈칸, 열쇠, 문, 도착
// 빈칸인 경우 일반적인 형태로 이동
// 열쇠인 경우 비트마스킹으로 열쇠 현황을 갱신한 후 이동
// 문인 경우 열쇠를 가지고 있다면 이동
// 도착점이라면 이동한 후 성공 판정 - bfs 기반이므로 첫 번쨰로 도착한 것이 최단 거리임이 보장됨
// visit 관리에 주의 - 잘못하면 메모리 초과 가능성 높음