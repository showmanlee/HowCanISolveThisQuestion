// 보스몬스터 전리품
// https://www.acmicpc.net/problem/20005

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, n, p;
	cin >> m >> n >> p;
	vector<vector<char>> board(m, vector<char>(n));
	vector<prr> player(26);
	vector<int> reach(26, 987654321);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] >= 'a' && board[i][j] <= 'z') {
				player[board[i][j] - 'a'] = { {i, j}, 0 };
				reach[board[i][j] - 'a'] = 0;
			}
		}
	}
	for (int i = 0; i < p; i++) {
		char c;
		int d;
		cin >> c >> d;
		player[c - 'a'].second = d;
	}
	int bhp;
	cin >> bhp;
	int res = 0, minn = 987654321;
	for (int i = 0; i < 26; i++) {
		if (reach[i] == 0) {
			queue<prr> q;
			vector<vector<bool>> visit(m, vector<bool>(n));
			int sx = player[i].first.first;
			int sy = player[i].first.second;
			visit[sx][sy] = true;
			q.push({ {sx, sy}, 0 });
			while (!q.empty()) {
				int x = q.front().first.first;
				int y = q.front().first.second;
				int dist = q.front().second;
				q.pop();
				if (board[x][y] == 'B') {
					reach[i] = dist;
					minn = min(minn, dist);
					break;
				}
				for (int j = 0; j < 4; j++) {
					int xx = x + dx[j];
					int yy = y + dy[j];
					if (xx < 0 || yy < 0 || xx >= m || yy >= n || board[xx][yy] == 'X')
						continue;
					if (!visit[xx][yy]) {
						visit[xx][yy] = true;
						q.push({ {xx, yy}, dist + 1 });
					}
				}
			}
		}
	}
	int sec = minn;
	while (bhp > 0) {
		int hitter = 0;
		for (int i = 0; i < 26; i++) {
			if (reach[i] <= sec) {
				hitter++;
				bhp -= player[i].second;
			}
		}
		sec++;
		res = max(res, hitter);
		if (res == p)
			break;
	}
	cout << res << '\n';
}

// 서로 다른 위치에 있고 각각의 공격력을 가진 플레이어들이 필드에 생성된 보스몬스터를 때리기만 하면 전리품을 얻는다고 할 때, 전리품을 얻을 수 있는 사람의 수는?

// 각 플레이어는 한 칸을 이동할 때마다 1초씩 소모하고, 보스몬스터가 나타나면 최단경로(bfs)로 보스몬스터에 도달해 도달하는 순간부터 각자의 공격력으로 초당 1대씩 때리기 시작한다
// 각 플레이어는 동시에 적을 때리며, 한 대라도 적을 때리면 전리품을 얻는다 - 여기서는 얻는 '사람의 수'를 구하는 게 문제, 막타나 비율 등 더 깊게 들어갈 필요가 없음
// 또한 여러 플레이어가 같은 칸에 있어도 됨 - 플레이어 이동에 다른 플레이어까지 고려할 필요가 없음
// + 플레이어 아이디(소문자)가 반드시 순서대로 들어온다는 보장이 없음

// 보드를 입력받을 때 각 플레이어의 시작 위치를 기억해둔다 - 플레이어 데이터를 저장하는 배열은 26칸으로 구성하되, 플레이어 등장 여부 확인할 수 있도록 함
// 여기서는 player에 각 플레이어의 시작 위치 + 대미지를, reach에 보스 도달 시점 및 등장 여부를 기록
// 이후 등장한 플레이어에 대해 각각 bfs를 돌려 보스까지 도달하는 시간 기록 - 그 중 가장 짧은 타임을 따로 저장하기
// 마지막으로 가장 짧은 타임부터 도착한 사람(들)이 각각의 대미지로 보스를 공격해 hp가 0이 될 때까지 진행하기
// 여기서 때린 사람들이 플레이어 수와 동일해지면 더 이상 늘어나거나 줄어들 일이 없기 때문에 확인 직후 시뮬레이션 중단하기

// BOJ 600문제 돌파! - 플5까지 앞으로 67점!