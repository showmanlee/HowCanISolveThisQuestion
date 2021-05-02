// 새로운 게임 2
// https://www.acmicpc.net/problem/17837

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
			int px = -1, py = -1, pd = -1;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (!pos[i][j].empty()) {
						for (int l = 0; l < pos[i][j].size(); l++) {
							if (pos[i][j][l] == t) {
								px = i;
								py = j;
								pd = l;
							}
						}
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
				vector<int> np;
				for (int i = pd; i < pos[px][py].size(); i++)
					np.push_back(pos[px][py][i]);
				pos[px][py].erase(pos[px][py].begin() + pd, pos[px][py].end());
				if (board[nx][ny] == 1 && np.size() > 1) {
					for (int i = 0; i < np.size() / 2; i++)
						swap(np[i], np[np.size() - i - 1]);
				}
				if (pos[nx][ny].empty())
					pos[nx][ny] = np;
				else {
					for (int i : np)
						pos[nx][ny].push_back(i);
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
// - 각 말은 이동 중 다른 말 위에 올라탈 수 있다 - 자신이 이동하면 자신 위에 쌓인 말도 함께 움직이고, 자신이 다른 말 위에 쌓여있는 상태여도 이동할 수 있다
// - 각 턴에서, 모든 말은 번호 순서대로 아래와 같이 움직인다
//   - 기본적으로 해당 말이 가진 방향대로 한 칸씩 움직이며, 이동할 칸에 다른 말이 있다면 자신이 업은 말들과 함께 해당 말(들) 맨 위에 올라탄다
//   - 만약 이동할 칸이 빨간색 칸이라면 이동 전 자신의 칸에 쌓인 말들의 순서를 뒤집는다(ABCD -> DCBA)
//   - 만약 이동할 칸이 파란색 칸이거나 맵 바깥이라면 방향을 반대로 하여 한 칸 이동하는데, 그곳도 파란색 칸이거나 맵 바깥이라면 이동하지 않는다
// - 이렇게 진행하다가 한 칸에 4개 이상의 말이 올라가는 순간 게임이 종료된다

// 새로운 게임 1에서 바닥에 있지 않은 말들도 움직일 수 있도록 변경한 버전 - 기본적인 메커니즘은 새로운 게임 1과 동일
// 따라서 이동할 말 위치를 잡을 때 해당 말의 높이도 잡아줘야 함
// 또한 이동할 말들 역시 범위를 정해줘야 함 - 이동이 확정된 상황에서 아예 새로운 배열을 만들어 이동할 말들을 원래 칸에서 빼둔다
// 이동할 말들이 따로 빠진 것만 감안하고 수정하면 나머지는 1과 같음
