// 군대탈출하기
// https://www.acmicpc.net/problem/14948

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));
	int left = 0, right = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			right = max(right, board[i][j]);
		}
	}
	left = board[0][0];
	while (left <= right) {
		int mid = (left + right) / 2;
		vector<vector<vector<bool>>> visit(2, vector<vector<bool>>(n, vector<bool>(m)));
		queue<prr> q;
		q.push({ {0, 0}, 0 });
		visit[0][0][0] = true;
		bool done = false;
		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int brk = q.front().second;
			q.pop();
			if (x == n - 1 && y == m - 1) {
				done = true;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 0 || yy < 0 || xx >= n || yy >= m)
					continue;
				if (board[xx][yy] <= mid) {
					if (!visit[brk][xx][yy]) {
						visit[brk][xx][yy] = true;
						q.push({ {xx, yy}, brk });
					}
				}
				else if (brk == 0) {
					xx += dx[i];
					yy += dy[i];
					if (xx < 0 || yy < 0 || xx >= n || yy >= m)
						continue;
					if (board[xx][yy] <= mid) {
						if (!visit[1][xx][yy]) {
							visit[1][xx][yy] = true;
							q.push({ {xx, yy}, 1 });
						}
					}
				}
			}
		}
		if (done)
			right = mid - 1;
		else
			left = mid + 1;
	}
	cout << left << '\n';
}

// 각 칸마다 접근할 수 있는 레벨이 있는 n*m 보드에서 좌측 상단에서 우측 하단으로 이동할 때 단 한 번 같은 방향으로 두 칸 이동할 수 있을 때, 이동하기 위해 필요한 최소 레벨은?

// 다익스트라로도 풀 수 있다지만, 여기서는 bfs + 이분 탐색을 사용해서 풀어봅시다
// 이분 탐색에서의 mid값이 현재 나의 레벨 - 레벨에 만족하는 칸을 발견하면 그냥 이동하고, 그렇지 않다면 한칸 뛰어서 생각하기
// 이동에 여러 방법이 있으니 bfs visit는 다차원으로 관리해야 함 - 장비를 안 썼나 썼나

// 보드를 받으며 레벨의 최댓값을 찾고, left는 출발점의 레벨, right는 최댓값으로 초기화 - 출발점을 밟을 수도 없으면 탐색 자체가 불가능하니
// 이후 이분 탐색과 함께 bfs를 돌리며 도착지에 도달했다면 right를 줄이고, 그렇지 않다면 left를 올린다 - 레벨이 높으면 갈 수 있는 곳도 많아짐
// 이렇게 이분 탐색이 끝나면 left값 출력하기