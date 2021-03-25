// 팩맨
// https://www.acmicpc.net/problem/11451

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
typedef pair<int, int> pr;
typedef tuple<pr, pr, string> tpps;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

char ds[4] = { 'S', 'E', 'N', 'W' };
int visit[51][51][51][51];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n, m;
		cin >> n >> m;
		int px1 = -1, py1, px2, py2;
		vector<vector<char>> board(n, vector<char>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> board[i][j];
				if (board[i][j] == 'P') {
					if (px1 == -1) {
						px1 = i;
						py1 = j;
					}
					else {
						px2 = i;
						py2 = j;
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				for (int k = 0; k < n; k++)
					for (int l = 0; l < m; l++)
						visit[i][j][k][l] = 987654321;
		string res = "IMPOSSIBLE";
		queue<tpps> q;
		q.push({ {px1, py1}, {px2, py2}, "" });
		visit[px1][py1][px2][py2] = 1;
		while (!q.empty()) {
			int x1 = get<0>(q.front()).first;
			int y1 = get<0>(q.front()).second;
			int x2 = get<1>(q.front()).first;
			int y2 = get<1>(q.front()).second;
			string route = get<2>(q.front());
			q.pop();
			if (x1 == x2 && y1 == y2) {
				res = route;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int xx1 = (x1 + n + dx[i]) % n;
				int yy1 = (y1 + m + dy[i]) % m;
				int xx2 = (x2 + n + dx[i]) % n;
				int yy2 = (y2 + m + dy[i]) % m;
				if (board[xx1][yy1] == 'G' || board[xx2][yy2] == 'G')
					continue;
				if (board[xx1][yy1] == 'X') {
					xx1 = x1;
					yy1 = y1;
				}
				if (board[xx2][yy2] == 'X') {
					xx2 = x2;
					yy2 = y2;
				}
				if (visit[xx1][yy1][xx2][yy2] > visit[x1][y1][x2][y2] + 1) {
					visit[xx1][yy1][xx2][yy2] = visit[x1][y1][x2][y2] + 1;
					q.push({ {xx1, yy1}, {xx2, yy2}, route + ds[i] });
				}
			}
		}
		if (res != "IMPOSSIBLE")
			cout << res.length() << ' ';
		cout << res << '\n';
	}
}

// 두 개의 팩맨이 서로 다른 위치에 있을 때, 하나로 합칠 수 있는 최소 횟수와 그 경로는?
// 보드에서 벗어나면 반대 방향에서 등장하고, 벽을 넘을 수는 없으며, 유령에 닿으면 죽는다

// 최소 거리는 bfs - 위치를 2개 관리하면서 경로까지 따져야 하는 bfs
// visit는 두 팩맨을 동시에 고려하면서 돌려야 함 - 4차원 전역 배열!
// 단순 bool visit보다는 해당 위치에서 진행한 최소 거리를 기록하는 int visit로 설정
// 경로는 문자열로 나타내면 되니까 큐 안에 경로까지 담아서 써보자 - bfs는 최소 경로 찾는 알고리즘이니까
// 이렇게 돌리다가 두 팩맨이 하나로 합쳐지면 탈출하고 출력

// 참고로 pair를 여러 번 쓸 필요 없이 tuple 하나면 여러 개의 자료형을 하나로 묶을 수 있습니다 - 잘 써먹으세요
// 원소 확인은 get<0>(tp)(인덱스 숫자)로 하고, #include <tuple>을 해야 합니다
// 사실 struct 만드는 게 더 편하고 직관적이지만, 한 줄로 큐에 넣을 수 있다는 장점이 있어서...