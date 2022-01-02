// 새로운 게임
// https://www.acmicpc.net/problem/17780

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<vector<int>> board(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];
	vector<int> dir(k + 1);
	vector<vector<vector<int>>> pos(n + 1, vector<vector<int>>(n + 1));
	for (int i = 1; i <= k; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		pos[x][y].push_back(i);
		dir[i] = d;
	}
	int res = 1;
	while (res <= 1000) {
		bool over = false;
		for (int t = 1; t <= k; t++) {
			int px = -1, py = -1;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (!pos[i][j].empty() && pos[i][j][0] == t) {
						px = i;
						py = j;
					}
				}
			}
			if (px == -1)
				continue;
			int nx = px + dx[dir[t]];
			int ny = py + dy[dir[t]];
			if (nx <= 0 || ny <= 0 || nx > n || ny > n || board[nx][ny] == 2) {
				dir[t] += (dir[t] % 2 == 0 ? -1 : 1);
				nx = px + dx[dir[t]];
				ny = py + dy[dir[t]];
			}
			if (nx <= 0 || ny <= 0 || nx > n || ny > n || board[nx][ny] == 2)
				continue;
			if (board[nx][ny] != 2) {
				if (board[nx][ny] == 1 && pos[px][py].size() > 1) {
					for (int i = 0; i < pos[px][py].size() / 2; i++)
						swap(pos[px][py][i], pos[px][py][pos[px][py].size() - i - 1]);
				}
				if (pos[nx][ny].empty())
					swap(pos[nx][ny], pos[px][py]);
				else {
					for (int i : pos[px][py])
						pos[nx][ny].push_back(i);
					pos[px][py].clear();
				}
			}
			if (pos[nx][ny].size() >= 4) {
				over = true;
				break;
			}
		}
		if (over)
			break;
		res++;
	}
	if (res > 1000)
		res = -1;
	cout << res << '\n';
}

// n*n 보드에서 k개의 말을 이용해 하는 새로운 게임이 있을 때, 해당 게임이 몇 턴 만에 끝나는가(1000턴 넘으면 -1)?
// - 보드의 각 칸에는 흰색, 빨간색, 파란색이 칠해져 있고, 각 말은 각자의 번호와 방향을 가지고 있다
// - 각 말은 이동 중 다른 말 위에 올라탈 수 있다 - 이동은 맨 아래에 있는 말만 가능하며, 올라탄 말(들)은 개별적으로 움직일 수 없다(자기 차례가 와도 넘어간다)
// - 각 턴에서, 모든 말은 번호 순서대로 아래와 같이 움직인다
//   - 기본적으로 해당 말이 가진 방향대로 한 칸씩 움직이며, 이동할 칸에 다른 말이 있다면 자신이 업은 말들과 함께 해당 말(들) 맨 위에 올라탄다
//   - 만약 이동할 칸이 빨간색 칸이라면 이동 전 자신의 칸에 쌓인 말들의 순서를 뒤집는다(ABCD -> DCBA)
//   - 만약 이동할 칸이 파란색 칸이거나 맵 바깥이라면 방향을 반대로 하여 한 칸 이동하는데, 그곳도 파란색 칸이거나 맵 바깥이라면 이동하지 않는다
// - 이렇게 진행하다가 한 칸에 4개 이상의 말이 올라가는 순간 게임이 종료된다

// 특별한 분기 없이 시키는 대로 구현하기만 하면 되는 문제 - 초기 계획을 어떻게 잡느냐가 중요
// 여기서는 각 칸의 색을 저장하는 2차원 배열 board, 각 말의 방향을 저장하는 dir, 각 칸의 쌓인 말을 vector로 저장하는 3차원 배열 pos로 현재 상황을 저장한다
// 이후 매 턴을 반복문으로 진행하는데, 현재 이동할 말이 pos 각 칸의 맨 아래에 있지 않다면 이동을 진행하지 않는다
// 만약 해당 말이 이동할 수 있는 칸이면 이동할 칸을 잡는데, 여기서 파란색 칸/맵 바깥 판정은 정방향/역방향으로 두 번 진행한다
// 그리고 이동할 칸을 보며 빨간색 칸이면 pos의 칸들을 미리 뒤집고 들어간다
// 이동 후 이동한 pos에 말이 4개 이상 쌓이면 즉시 중단