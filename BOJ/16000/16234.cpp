// 인구 이동
// https://www.acmicpc.net/problem/16234

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	int n, l, r;
	cin >> n >> l >> r;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	int res = 0;
	while (true) {
		bool flag = true;
		vector<vector<int>> room(n, vector<int>(n, -1));
		vector<int> sum, div;
		int count = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (room[i][j] == -1) {
					room[i][j] = ++count;
					sum.push_back(board[i][j]);
					div.push_back(1);
					queue<pr> q;
					q.push({ i, j });
					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						for (int i = 0; i < 4; i++) {
							int xx = x + dx[i];
							int yy = y + dy[i];
							if (xx < 0 || yy < 0 || xx >= n || yy >= n)
								continue;
							int d = abs(board[x][y] - board[xx][yy]);
							if (room[xx][yy] == -1 && d >= l && d <= r) {
								flag = false;
								room[xx][yy] = count;
								sum[count] += board[xx][yy];
								div[count]++;
								q.push({ xx, yy });
							}
						}
					}
				}
			}
		}
		if (flag)
			break;
		res++;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				board[i][j] = sum[room[i][j]] / div[room[i][j]];
	}
	cout << res << '\n';
}

// n*n칸의 땅에서 각 칸의 인구가 아래의 규칙에 따라 인구 이동을 할 때, 인구 이동이 몇 번 발생하고 멈추는가?
// - 맞닿아있는 땅의 인구 차이가 l명 이상, r명 이하라면 국경을 연다
// - 이렇게 열린 국경끼리 이어진 땅의 인구수는 (이어진 땅의 인구수의 합 / 이어진 땅의 수)가 된다
// - 이 과정이 끝나면 모든 국경은 다시 닫힌다
// - 위의 과정을 인구 이동이 없을 때까지 반복한다

// 덩어리를 산출하는데 가장 적합한 방법은 BFS
// 땅을 하나씩 순회하면서, 연합 번호가 안 달린 땅이라면 연합 번호를 매기고 bfs로 연합이 될 수 있는 모든 땅에 같은 번호를 매긴다
// 그 과정에서 같은 번호를 공유하는 인구의 합과 땅의 수를 모은 뒤, 모든 칸의 순회가 끝나면 인구를 갱신한다
// 만약 bfs를 통한 번호 갱신이 발생하지 않은 경우 탈출