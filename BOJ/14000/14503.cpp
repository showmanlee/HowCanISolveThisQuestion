// 로봇 청소기
// https://www.acmicpc.net/problem/14503

#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));
	vector<vector<bool>> visit(n, vector<bool>(m));
	prr robot;
	cin >> robot.first.first >> robot.first.second >> robot.second;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	while (true) {
		visit[robot.first.first][robot.first.second] = true;
		bool flag = false;
		for (int i = 0; i < 4; i++) {
			robot.second = (robot.second + 3) % 4;
			int xx = robot.first.first + dx[robot.second];
			int yy = robot.first.second + dy[robot.second];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m)
				continue;
			if (board[xx][yy] == 0) {
				if (!visit[xx][yy]) {
					robot.first = { xx, yy };					
					flag = true;
					break;
				}
			}
		}
		if (flag)
			continue;
		int xx = robot.first.first + dx[(robot.second + 2) % 4];
		int yy = robot.first.second + dy[(robot.second + 2) % 4];
		if (xx < 0 || yy < 0 || xx >= n || yy >= m)
			break;
		if (board[xx][yy] == 0)
			robot.first = { xx, yy };
		else
			break;
	}
	int res = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (visit[i][j])
				res++;

	cout << res << '\n';
}

// 아래 규칙대로 움직이는 로봇청소기가 주어진 위치에 주어진 방향으로 놓였을 때, 로봇청소기가 청소하는 칸 수는?
// 1. 현재 위치를 청소한다
// 2. 현재 위치에서 현재 방향을 기준으로 왼쪽 방향부터 탐색하여
//  - 왼쪽 방향에 벽이 아니면서 청소하지 않은 공간이 있으면 그 방향으로 전진, 1.부터 반복
//  - 그렇지 않다면 회전만 한 뒤 한 바퀴 돌기 전까지 2. 반복
//  - 만약 한 바퀴를 돌았는데 내 뒷 공간이 벽이 아니라면 해당 공간으로 한칸 후진, 2. 반복
//  - 그렇지도 않다면 작동 중지

// 상황에 따라 dfs를 적용할 수도 있고, while true를 적용할 수도 있었음
// 시키는 대로 로봇을 왼쪽으로 돌려가면서 구현하기