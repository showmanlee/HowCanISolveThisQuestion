// 일요일 아침의 데이트
// https://www.acmicpc.net/problem/1445

#include <iostream>
#include <vector>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, pr> prrr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	vector<pr> gpos;
	int sx, sy, gx, gy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			if (board[i][j] == 'F') {
				gx = i;
				gy = j;
			}
			if (board[i][j] == 'g')
				gpos.push_back({ i, j });
		}
	}
	for (pr p : gpos) {
		for (int i = 0; i < 4; i++) {
			int xx = p.first + dx[i];
			int yy = p.second + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m)
				continue;
			if (board[xx][yy] == '.')
				board[xx][yy] = 'h';
		}
	}
	priority_queue<prrr> pq;
	vector<vector<bool>> visit(n, vector<bool>(m));
	pq.push({ {0, 0}, {sx, sy} });
	visit[sx][sy] = true;
	while (!pq.empty()) {
		int ga = -pq.top().first.first;
		int gb = -pq.top().first.second;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (x == gx && y == gy) {
			cout << ga << ' ' << gb << '\n';
			break;
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m || visit[xx][yy])
				continue;
			visit[xx][yy] = true;
			if (board[xx][yy] == 'F')
				pq.push({ {-ga, -gb}, {xx, yy} });
			if (board[xx][yy] == 'g')
				pq.push({ { -ga - 1, -gb }, { xx, yy } });
			else if (board[xx][yy] == 'h')
				pq.push({ {-ga, -gb - 1}, {xx, yy} });
			else if (board[xx][yy] == '.')
				pq.push({ {-ga, -gb}, {xx, yy} });
		}
	}
}

// 쓰레기와 쓰레기 옆을 피해 꽃이 있는 곳으로 이동할 때, 밟아야만 하는 쓰레기와 쓰레기 옆칸의 최소 개수는?

// 다익스트라 원리로 풀 수 있는 문제 - 쓰레기가 포함된 간선마다 가중치를 주지 말고, 만난 쓰레기의 수와 쓰레기 옆칸의 수를 가중치 삼아 돌린다
// pq 안에서 쓰레기 -> 옆칸의 우선순위로 최소 힙이 작동되도록 설정하기
// 더 편리한 옆칸 판정을 위해 탐색 시작 전 쓰레기 옆칸을 보드에 기록하기 - 여기서는 'h'로 기록
// 이렇게 변형 다익스트라를 돌리며 도착지에 처음으로 도달하는 상황에서 기록된 칸 개수가 정답
// 출발지와 도착지는 '쓰레기 옆칸'으로 카운트되지 않음에 주의 - 시작칸과 도착칸을 지우지 않기