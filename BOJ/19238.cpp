// 스타트 택시
// https://www.acmicpc.net/problem/19238

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;
typedef tuple<int, pr, int> tpipi;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, fuel;
	cin >> n >> m >> fuel;
	vector<vector<int>> board(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];
	int sx, sy;
	cin >> sx >> sy;
	vector<pr> destination(m + 2);
	for (int i = 2; i < m + 2; i++) {
		int ax, ay, bx, by;
		cin >> ax >> ay >> bx >> by;
		board[ax][ay] = i;
		destination[i] = { bx, by };
	}
	int remain = m;
	int res = -1;
	while (remain > 0) {
		vector<vector<bool>> visit_start(n + 1, vector<bool>(n + 1));
		queue<prr> q;
		vector<tpipi> candidate;
		q.push({ {sx, sy}, 0 });
		visit_start[sx][sy] = true;
		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int f = q.front().second;
			q.pop();
			if (board[x][y] >= 2) 
				candidate.push_back({ f, {x, y}, board[x][y] });
			if (f == fuel)
				continue;
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx <= 0 || yy <= 0 || xx > n || yy > n || visit_start[xx][yy])
					continue;
				if (board[xx][yy] != 1) {
					visit_start[xx][yy] = true;
					q.push({ {xx, yy}, f + 1 });
				}
			}
		}
		if (candidate.empty())
			break;
		sort(candidate.begin(), candidate.end());
		int dest = get<2>(candidate[0]);
		int rf = fuel - get<0>(candidate[0]);
		sx = get<1>(candidate[0]).first;
		sy = get<1>(candidate[0]).second;

		bool fail = true;
		vector<vector<bool>> visit_end(n + 1, vector<bool>(n + 1));
		q.push({ {sx, sy}, 0 });
		visit_end[sx][sy] = true;
		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int f = q.front().second;
			q.pop();
			if (destination[dest].first == x && destination[dest].second == y) {
				board[sx][sy] = 0;
				fuel = rf + f;
				sx = x;
				sy = y;
				fail = false;
				break;
			}
			if (f == rf && board[x][y] != -dest)
				continue;
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx <= 0 || yy <= 0 || xx > n || yy > n || visit_end[xx][yy])
					continue;
				if (board[xx][yy] != 1) {
					visit_end[xx][yy] = true;
					q.push({ {xx, yy}, f + 1 });
				}
			}
		}
		if (fail)
			break;
		remain--;
		if (remain == 0)
			res = fuel;
	}
	cout << res << '\n';
}
// 서로 다른 위치에 있는 승객이 n*n 보드에서 연료 개념이 있는 택시를 기다릴 때, 택시를 다음과 같이 운행하여 남기는 연료량은?
// - 연료는 한 칸을 이동할 때마다 1씩 줄어든다
// - 우선 지도에 남은 승객 중 가장 가까운 승객을 태우는데, 같은 거리의 승객이 있으면 x -> y가 작은 순서대로 우선순위를 둔다
// - 승객을 태운 후 각 승객의 목적지에 성공적으로 도착하면 그 승객을 태워 이동한 거리의 두 배의 연료가 채워진다(최대 연료량은 무제한)
// - 모든 이동은 최단경로로 한다 - bfs
// 모든 출발지는 다르지만, 도착지는 동일할 수 있음에 주의 - 누군가의 출발지가 누군가의 도착지가 될 수 있음에도 주의
// 또한 목적지 도달 시점에서 연료가 0이 되어도 실패 판정이 아님에 주의

// 우선 보드 입력을 받고, 시작점 정보를 받는다
// 이후 각 승객의 시작점/도착점 정보를 받는다 - 시작점은 보드에 2 + i번으로 직접 표시하고, 도착점은 별도의 배열에 2 + i번 인덱스로 저장한다
// 그러면서 남은 승객 수 변수를 만들어둔 뒤, 남은 승객이 없어질 때까지 반복문 돌입

// 첫 번째 bfs는 현재 택시 위치에서 연료 안에 태울 수 있는 승객 리스트를 만드는데 활용
// 좌표 순회 순서가 반드시 우선순위를 만족하는 것은 아니기에, 승객을 만나도 후보군에 넣고 bfs를 중단하지는 않음
// 만약 후보 승객이 없으면 바로 실패 판정
// 아니라면 승객 리스트를 정렬하여 두 번째 bfs에서 태울 승객을 결정하고, 해당 승객까지 도달한 연료량 빼주기
// 두 번째 bfs에서는 승객을 태우고 목적지까지 이동
// 목적지에 도달했다면 다음 회차의 시작 지점을 현재 목적지로 정하고, 연료를 채우고, 보드에 있던 승객을 지운다
// 만약 탐색에 실패했다면 바로 실패 판정