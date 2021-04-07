// 로봇
// https://www.acmicpc.net/problem/13901

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };

int main(void) {
	int r, c, k;
	cin >> r >> c >> k;
	vector<vector<bool>> board(r, vector<bool>(c));
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = true;
	}
	int x, y;
	cin >> x >> y;
	vector<int> dir(4);
	for (int i = 0; i < 4; i++)
		cin >> dir[i];
	int d = 0;
	int miss = 0;
	board[x][y] = true;
	while (true) {
		int xx = x + dx[dir[d]];
		int yy = y + dy[dir[d]];
		if (xx < 0 || yy < 0 || xx >= r || yy >= c || board[xx][yy]) {
			miss++;
			if (miss == 4) {
				cout << x << ' ' << y << '\n';
				break;
			}
			d = (d + 1) % 4;
			continue;
		}
		miss = 0;
		board[xx][yy] = true;
		x = xx;
		y = yy;
	}
}

// 장애물이 있는 r*c 보드에서 이동 방향 순서가 정해진 로봇이 계속 전진하다가 벽이나 이미 방문한 곳에 닿을 때 방향을 전환한다고 할 때, 이동이 불가능해지는 지점은?
// 내 앞에 장애물이나 방문한 곳이 있을 때 다음 방향으로 바꿔줘야 한다(순환)
// while true 안에서 내 다음 위치를 체크하는데, 못 가는 곳이라면 다음 방향으로 바꾸고, 그렇지 않으면 해당 위치로 이동한다
// miss 변수를 통해 탐색이 막힌 횟수를 기록하는데, 이동하는데 성공했다면 초기화하고 그렇지 않다면 추가해준다
// 그렇게 miss가 4가 되면 모든 곳이 막혔다는 의미이니 위치 출력 후 탈출