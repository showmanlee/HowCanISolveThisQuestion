// 선진이의 겨울 왕국
// https://www.acmicpc.net/problem/11567

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
	vector<vector<char>> board(n + 1, vector<char>(m + 1));
	vector<vector<int>> visit(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'X')
				visit[i][j] = 1;
		}
	}
	int sx, sy, gx, gy;
	cin >> sx >> sy >> gx >> gy;
	queue<pr> q;
	q.push({ sx, sy });
	visit[sx][sy] = 1;
	bool res = false;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == gx && y == gy && visit[x][y] == 2) {
			res = true;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx <= 0 || yy <= 0 || xx > n || yy > m)
				continue;
			if (xx == gx && yy == gy && visit[xx][yy] == 1) {
				visit[xx][yy] = 2;
				q.push({ xx, yy });
			}
			if (visit[xx][yy] == 0) {
				visit[xx][yy] = 1;
				q.push({ xx, yy });
			}
		}
	}
	cout << (res ? "YES" : "NO") << '\n';
}

// 불안정한 상태의 n*m 빙판에서 한 번 밟은 빙판은 금이 가서 또 밟았을 때 깨지는 상태고, 도착점의 얼음은 반드시 깨야 할 때, 그렇게 할 수 있는가?
// 단, 얼음을 그 자리에서 깰 수는 없고, 도착점이 아닌 금이 간 빙판을 밟으면 죽는다

// 한 번 지나간 곳은 다시 밟을 수 없지만, 도착점은 다시 밟을 수 있는 bfs
// 보드를 받고, 해당 보드에서 깨진 부분은 visit 배열에서 방문했다고 표기 - 방문은 bool 개념이 아닌 int로 접근하여, 방문점은 1로 표기
// 이후 출발점부터 bfs를 돌리면서 방문하지 않은 곳들을 평소처럼 방문
// 그러나 방문할 점이 도착점이라면 이미 방문한 곳이더라도 다시 방문 - 이 경우 visit를 2로 맞춤
// 그 결과 도착점이 큐에 두 번 들어오게 된 경우, 결과값을 YES로 바꾸고 탐색 종료
// 만약 그러지 않고 자연스럽게 탐색이 종료된 경우 결과값은 NO가 되겠지