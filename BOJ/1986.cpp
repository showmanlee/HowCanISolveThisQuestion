// 체스
// https://www.acmicpc.net/problem/1986

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<pair<int, int>, int> prr;
int dx_q[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
int dy_q[8] = { 1, 0, -1, -1, -1, 0, 1, 1 };
int dx_k[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy_k[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n + 1, vector<int>(m + 1));
	vector<vector<bool>> visit(n + 1, vector<bool>(m + 1));
	queue<prr> q;
	int queen;
	cin >> queen;
	for (int i = 0; i < queen; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
		visit[a][b] = true;
		q.push({ {a, b}, 1 });
	}
	int knight;
	cin >> knight;
	for (int i = 0; i < knight; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = 2;
		visit[a][b] = true;
		q.push({ {a, b}, 2 });
	}
	int pawn;
	cin >> pawn;
	for (int i = 0; i < pawn; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = 3;
		visit[a][b] = true;
	}
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int type = q.front().second;
		q.pop();
		if (type == 1) {
			for (int i = 0; i < 8; i++) {
				int xx = x, yy = y;
				while (true) {
					xx += dx_q[i];
					yy += dy_q[i];
					if (xx <= 0 || yy <= 0 || xx > n || yy > m)
						break;
					if (board[xx][yy] == 0)
						visit[xx][yy] = true;
					else
						break;
				}
			}
		}
		else {
			for (int i = 0; i < 8; i++) {
				int xx = x + dx_k[i];
				int yy = y + dy_k[i];
				if (xx <= 0 || yy <= 0 || xx > n || yy > m)
					continue;
				if (board[xx][yy] == 0)
					visit[xx][yy] = true;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!visit[i][j])
				res++;
	cout << res << '\n';
}

// 체스 판에 나이트, 퀸, 폰이 있을 때, 다음 턴에 이들에게 먹히지 않을 수 있는 안전 구역의 수는?
// 다음 턴만 계산하면 됨 - 나이트는 나이트 이동으로 한 칸씩, 퀸은 전후좌우대각선으로 스트레이트, 폰은 그냥 그 자리에
// 모든 말을 동시에 움직이는 것이 아님 - 만약 한 말이 이동하려는 곳에 다른 말이 있다면 그 곳으로는 이동할 수 없음
// 이를 고려해 각 말이 처음 위치한 곳과 이동할 수 있는 곳을 모두 표시한 후, 표시되지 않은 곳의 수를 세면 그게 결과가 됨
// 따로 주어지는 각 말들의 이동을 통합해서 처리하기 위해 큐 사용 - 나이트와 퀸만 받고, 폰은 못 움직이니 제외
// 한 말이 이동했던 곳이더라도 다른 말이 이동할 수 있음 - 장애물 판정은 visit가 아닌 board로 판정