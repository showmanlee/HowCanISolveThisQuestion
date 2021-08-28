// 영상처리
// https://www.acmicpc.net/problem/21938

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
	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a, b, c;
			cin >> a >> b >> c;
			board[i][j] = (a + b + c) / 3;
		}
	}
	int t;
	cin >> t;
	int res = 0;
	vector<vector<bool>> visit(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && board[i][j] >= t) {
				visit[i][j] = true;
				res++;
				queue<pr> q;
				q.push({ i, j });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int p = 0; p < 4; p++) {
						int xx = x + dx[p];
						int yy = y + dy[p];
						if (xx < 0 || yy < 0 || xx >= n || yy >= m || visit[xx][yy])
							continue;
						if (board[xx][yy] >= t) {
							visit[xx][yy] = true;
							q.push({ xx,yy });
						}
					}
				}
			}
		}
	}
	cout << res << '\n';
}

// 한 픽셀의 rgb값의 평균이 경계값 이상이면 그 픽셀에 물체가 있다고 판정할 때, 화면 속 물체의 개수는?

// 물체가 있는 픽셀이 상하좌우로 접하면 한 물체로 간주 - 즉 전처리 과정이 필요한 bfs 개수 구하기 문제
// 픽셀을 받을 때 rgb를 받아서 그 평균값을 배열에 저장 - double로 변환하지 않아도 됨
// 이후 모든 픽셀을 순회하며 물체 판정(visit)을 받지 않았는데 픽셀값이 경계값 이상이면 결과값을 1 올리고 해당 위치를 기준으로 bfs 돌입 - 해당 위치에서 만나는 경계값 이상의 픽셀을 체크해준다
// 그렇게 센 물체의 수가 곧 답