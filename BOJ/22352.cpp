// 항체 인식
// https://www.acmicpc.net/problem/22352

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> before(n, vector<int>(m)), after(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> before[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> after[i][j];
	vector<vector<int>> section(n, vector<int>(m));
	int sec = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (section[i][j] == 0) {
				sec++;
				section[i][j] = sec;
				queue<pr> q;
				q.push({ i, j });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int t = 0; t < 4; t++) {
						int xx = x + dx[t];
						int yy = y + dy[t];
						if (xx < 0 || yy < 0 || xx >= n || yy >= m)
							continue;
						if (before[x][y] == before[xx][yy] && section[xx][yy] == 0) {
							section[xx][yy] = sec;
							q.push({ xx, yy });
						}
					}
				}
			}
		}
	}
	bool res = true;
	int cnt = 0;
	vector<vector<bool>> visit(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j]) {
				queue<pr> q;
				visit[i][j] = true;
				q.push({ i, j });
				int key = after[i][j];
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					if (after[x][y] != key) {
						res = false;
						break;
					}
					for (int t = 0; t < 4; t++) {
						int xx = x + dx[t];
						int yy = y + dy[t];
						if (xx < 0 || yy < 0 || xx >= n || yy >= m)
							continue;
						if (section[x][y] == section[xx][yy] && !visit[xx][yy]) {
							visit[xx][yy] = true;
							q.push({ xx, yy });
						}
					}
				}
				if (after[i][j] != before[i][j])
					cnt++;
				if (cnt > 1)
					res = false;
				if (!res)
					break;
			}
		}
		if (!res)
			break;
	}
	cout << (res ? "YES" : "NO") << '\n';
}

// 각 칸에 번호가 주어진 n*m 조직의 한 칸에 약을 투약하면 해당 칸 주변의 번호가 같은 칸들의 번호가 무작위로 바뀐다
// 두 조직의 촬영 결과가 주어졌을 때, 투약한 결과로 볼 수 있는가?

// 그러니까 각 칸에 번호가 적힌 n*m 공간에서 어떤 한 덩어리의 숫자를 바꿨다고 할 때, 주어진 두 공간이 이러한 처리를 한 결과인지 판정하는 문제
// bfs 영역 탐색 문제라는 뜻 - 우선 before, after라는 두 공간을 입력받는다
// before에 대해서는 영역을 따기 위한 bfs를 돌린다 - 인접한 칸에 같은 번호가 있다면 동일한 영역으로 판단, 각 영역마다 고유 번호를 매긴다
// after에 대해서는 앞서 따놓은 영역 단위로 순회하며 정답 여부를 판정한다
// 탐색을 시작하는 칸의 after 상의 번호를 따두고, '영역'을 기준으로 bfs를 돌리며 after의 '영역' 안의 번호가 모두 같은지부터 확인 - 같지 않으면 fail
// 만약 같았다면 before와 after의 영역 번호가 같았는지 확인 - 같지 않은 영역이 2개 이상이면 fail
// 이렇게 실패 여부를 판정한 뒤 결과 출력하기