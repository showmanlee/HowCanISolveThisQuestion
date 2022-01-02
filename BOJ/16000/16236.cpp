// 아기 상어
// https://www.acmicpc.net/problem/16236

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, pr> prr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	int sx, sy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				sx = i;
				sy = j;
				board[i][j] = 0;
			}
		}
	}
	int size = 2, eaten = 0;
	int res = 0;
	while (true) {
		vector<vector<bool>> visit(n, vector<bool>(n));
		vector<prr> candidate;
		queue<prr> q;
		q.push({0, {sx, sy}});
		visit[sx][sy] = true;
		while (!q.empty()) {
			int dist = q.front().first;
			int x = q.front().second.first;
			int y = q.front().second.second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 0 || yy < 0 || xx >= n || yy >= n || visit[xx][yy])
					continue;
				if (board[xx][yy] <= size) {
					visit[xx][yy] = true;
					q.push({ dist + 1, {xx, yy} });
					if (board[xx][yy] != 0 && board[xx][yy] < size)
						candidate.push_back({ dist + 1, {xx, yy} });
				}
			}
		}
		if (candidate.empty())
			break;
		sort(candidate.begin(), candidate.end());
		board[candidate[0].second.first][candidate[0].second.second] = 0;
		sx = candidate[0].second.first;
		sy = candidate[0].second.second;
		res += candidate[0].first;
		eaten++;
		if (eaten == size) {
			size++;
			eaten = 0;
		}
	}
	cout << res << '\n';
}

// 크기가 2인 아기 상어와 다양한 크기의 물고기들이 있을 때, 아기 상어가 물고기를 먹으면서 다닐 수 있는 시간은?
// 아기 상어는 자신보다 작은 물고기만 먹을 수 있고, 자신의 크기만큼의 물고기를 먹으면 성장한다
// 자신과 같은 크기의 물고기가 있는 칸에는 먹진 못하지만 도달할 수는 있고, 자신보다 큰 물고기의 칸에는 접근할 수 없다
// 물고기는 가장 가까운 물고기부터, 거리가 같다면 상단, 좌측의 물고기부터 먹는다

// 먹는 규칙이 정해져있기 때문에 문제에서 묻는 게 '최단' 거리가 아님 - 정확히는 조건 안에 최소가 명시되어 있긴 함
// 아무튼 최단 거리를 찾아야 되니 bfs를 사용
// 일단 먹을 수 있는 물고기가 없을 때까지 bfs를 계속 돌려줘야 한다
// 그 안에서 먹을 수 있는 물고기가 발견되면 결과에 거리를 누적시킨 후, 해당 위치에서 bfs를 다시 돌린다
// 그런데 먹을 수 있는 물고기가 여러 개일 수 있음 - 게다가 물고기 우선순위에 좌표도 영향을 미침 - bfs 방향 우선 순위는 물고기 우선순위와 다를 수도 있음
// 따라서 먹을 수 있는 물고기를 찾았다고 바로 bfs를 중단해서는 안됨 - 대신 해당 물고기를 후보군 배열에 넣어줘야 함
// 만약 후보군이 없으면 결과 출력, 그렇지 않다면 정렬 후 최우선 후보까지 도달한 거리를 누적
// 정렬은 기본 sort 함수 사용 - prr 순서를 거리, x, y 순으로 적용하여 차례대로 정렬되도록