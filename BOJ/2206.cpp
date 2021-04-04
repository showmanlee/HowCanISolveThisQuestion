// 벽 부수고 이동하기
// https://www.acmicpc.net/problem/2206

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<pair<int, int>, pair<int, int>> prrr;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	vector<vector<vector<bool>>> visit(n, vector<vector<bool>>(m, vector<bool>(2)));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	int res = -1;
	queue<prrr> q;
	q.push({ {0, 0}, {1, 0} });
	visit[0][0][0] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second.first;
		int broke = q.front().second.second;
		if (x == n - 1 && y == m - 1) {
			res = dist;
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m)
				continue;
			if (broke == 0 && board[xx][yy] == '1') {
				visit[xx][yy][1] = true;
				q.push({ {xx, yy}, {dist + 1, 1} });
			}
			else if (!visit[xx][yy][broke] && board[xx][yy] == '0') {
				visit[xx][yy][broke] = true;
				q.push({ {xx, yy}, {dist + 1, broke} });
			}
		}
	}
	cout << res << '\n';
}

// 좌측 상단에서 우측 하단까지 이동하기 위해 하나의 벽을 부술 수 있을 때, 도달하는 최소 거리는?
// 굳이 브루트포스를 안 쓰더라도 bfs 한번으로 처리할 수 있음 - 애초에 브루트포스 돌리기에는 최대 백만 개라 부담스러움

// 원래 접근 : bfs w/ 벽을 부쉈는가 표시하는 bool 태그 - 벽을 안 부순 상태라면 벽이 있는 곳으로 도달할 수 있게 설정
// 하나의 bfs 안에서도 벽 파괴 여부에 따라 다양한 경우가 나올 수 있기 때문에 visit 대신 dist 개념으로 접근해야 하려고 했음 - bfs 경로 길이 문제에서 내가 쓰는 방법
// 근데 문제는 그게 안 됨 - 어떤 벽을 부쉈느냐에 따라 다양한 dist가 나올 수 있고, min을 적용한 dist + bool 태그로는 정확한 최소 길이를 알아낼 수 없음

// 다른 방법 - visit를 벽을 부쉈느냐 안 부쉈냐를 따로 둬 2차원으로 만들고, 거리 측정은 queue 선에서 해결한다 - 거리를 따로따로 보존
// bfs 순회 과정에서 벽을 부쉈다면 파괴 태그를 1로 바꾸고 visit도 파괴 버전으로 체크하고 삽입 - 이후에도 파괴 버전에서 체크
// '파괴했나'는 했냐 안했냐로만 나오기에 '파괴한 상태에서 들렀어요'는 벽의 수만큼 생성할 필요가 없음 - 파괴 경우에 대한 수많은 거리 정보는 queue에서 해결
// 그 이후에는 여느 bfs와 마찬가지로 가장 먼저 우측 하단에 도달하는 거리가 최소 거리가 됨