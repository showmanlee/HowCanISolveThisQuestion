// 구슬 탈출 3
// https://www.acmicpc.net/problem/15644

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef tuple<pr, pr, int, string> tpppis;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string dir = "DRUL";

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	vector<vector<vector<vector<bool>>>> visit(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(n, vector<bool>(m))));
	pr r, b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				r = { i, j };
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				b = { i, j };
				board[i][j] = '.';
			}
		}
	}
	int rest = -1;
	string ress;
	queue<tpppis> q;
	q.push({ r, b, 0, "" });
	visit[r.first][r.second][b.first][b.second] = true;
	while (!q.empty()) {
		int rx = get<0>(q.front()).first;
		int ry = get<0>(q.front()).second;
		int bx = get<1>(q.front()).first;
		int by = get<1>(q.front()).second;
		int time = get<2>(q.front());
		string route = get<3>(q.front());
		bool done = false;
		q.pop();
		if (time >= 10)
			continue;
		for (int i = 0; i < 4; i++) {
			int rxx = rx;
			int ryy = ry;
			int bxx = bx;
			int byy = by;
			int tr = 0;
			int tb = 0;
			while (board[rxx + dx[i]][ryy + dy[i]] != '#') {
				rxx += dx[i];
				ryy += dy[i];
				tr++;
				if (board[rxx][ryy] == 'O')
					break;
			}
			while (board[bxx + dx[i]][byy + dy[i]] != '#') {
				bxx += dx[i];
				byy += dy[i];
				tb++;
				if (board[bxx][byy] == 'O')
					break;
			}
			if (board[bxx][byy] == 'O')
				continue;
			if (board[rxx][ryy] == 'O') {
				rest = time + 1;
				ress = route + dir[i];
				done = true;
				break;
			}
			if (rxx == bxx && ryy == byy) {
				if (tr > tb) {
					rxx -= dx[i];
					ryy -= dy[i];
				}
				else {
					bxx -= dx[i];
					byy -= dy[i];
				}
			}
			if (visit[rxx][ryy][bxx][byy])
				continue;
			visit[rxx][ryy][bxx][byy] = true;
			q.push({ {rxx, ryy}, {bxx, byy}, time + 1, route + dir[i] });
		}
		if (done)
			break;
	}
	cout << rest << '\n';
	if (rest != -1)
		cout << ress << '\n';
}

// 미로 안에 구멍과 빨강/파랑 구슬이 있는 장난감을 상하좌우로 기울여 파란 구슬은 빠뜨리지 않고 빨간 구슬만 빠뜨리려고 할 때, 10번 이내로 기울여서 성공할 수 있는가? 있다면 어떻게 가야 하는가?
// 구슬 탈출 2에서 이동 경로까지 출력해야 하는 버전
// 큐 tuple에 경로까지 저장하기 - 큐에 삽입할 때마다 그에 대응하는 경로 문자를 붙여서 넣어주기

// solved.ac 1000위권 진입! - 이제 유지해야 한다