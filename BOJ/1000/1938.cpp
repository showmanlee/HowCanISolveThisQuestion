// 통나무 옮기기
// https://www.acmicpc.net/problem/1938

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, pr> prr;
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { -1, 0, 1, 0, 0 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<char>> board(n, vector<char>(n));
	int sx, sy, sd, gx, gy, gd;
	int sc = 0, gc = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> board[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'B') {
				sc++;
				board[i][j] = '0';
				if (sc == 2) {
					sx = i;
					sy = j;
					sd = (i + 1 < n && board[i + 1][j] == 'B');
				}
			}
			if (board[i][j] == 'E') {
				gc++;
				board[i][j] = '0';
				if (gc == 2) {
					gx = i;
					gy = j;
					gd = (i + 1 < n && board[i + 1][j] == 'E');
				}
			}
		}
	}
	vector<vector<vector<bool>>> visit(n, vector<vector<bool>>(n, vector<bool>(2)));
	queue<prr> q;
	q.push({ {sx, sy}, {sd, 0} });
	visit[sx][sy][sd] = true;
	int res = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if (x == gx && y == gy && d == gd) {
			res = cnt;
			break;
		}
		for (int i = 0; i < 5; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			int dd = d;
			if (i == 4) {
				dd = !dd;
				bool pass = false;
				for (int xt = xx - 1; xt <= xx + 1; xt++)
					for (int yt = yy - 1; yt <= yy + 1; yt++)
						if (xt < 0 || yt < 0 || xt >= n || yt >= n || board[xt][yt] == '1')
							pass = true;
				if (pass)
					continue;
			}
			if (xx < 0 || yy < 0 || xx >= n || yy >= n)
				continue;
			bool pass = false;
			if (dd) {
				for (int xt = xx - 1; xt <= xx + 1; xt++)
					if (xt < 0 || xt >= n || board[xt][yy] == '1')
						pass = true;
			}
			else {
				for (int yt = yy - 1; yt <= yy + 1; yt++)
					if (yt < 0 || yt >= n || board[xx][yt] == '1')
						pass = true;
			}
			if (pass)
				continue;
			if (!visit[xx][yy][dd]) {
				visit[xx][yy][dd] = true;
				q.push({ {xx, yy}, {dd, cnt + 1} });
			}
		}
	}
	cout << res << '\n';
}

// n*n 공간에 놓인 길이가 3인 통나무를 목표 위치로 이동하기 위해 상하좌우 이동 및 90도 회전할 수 있을 때, 이를 위한 최소 행동 횟수는?

// 회전은 통나무의 중심 위치를 기준으로 90도 회전하는 것(방향은 의미없음) - 원점(통나무 중심)을 기준으로 8방항이 비어있어야 가능
// 회전을 기준으로 적용해야 하기에, 원점 위치(+ 방향)을 기준으로 탐색을 진행한다 - 최단 거리를 탐색해야 하므로 bfs 활용
// 우선 보드를 모두 받고, 받은 보드를 순회하며 통나무와 도착지의 위치를 찾는다
// 찾은 B/E의 수를 세고, 2번째 B/E를 발견한 경우 해당 위치를 출발/도착지로 잡고 이와 인접한 3번째 B/E의 위치를 보고 방향을 판정
// visit 배열 역시 가로/세로/방향 등 3차원으로 기록하기
// 큐 탐색 내부에서는 상하좌우 이동 및 90도 회전의 케이스를 탐색하는데, 회전하는 경우 원점 기준 8방향이 비어있는지, 이동하는 경우 해당 위치에 통나무가 들어갈 수 있는지 확인하기
// 모든 확인이 끝나면 큐에 이동/회전 결과 삽입 - 그리고 결과 위치/회전에 도달한 경우 측정한 길이를 결과값에 갱신시킨 후 출력