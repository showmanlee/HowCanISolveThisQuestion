// 회로배치
// https://www.acmicpc.net/problem/2645

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, pr> prr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int sx, sy, gx, gy;
	cin >> sx >> sy >> gx >> gy;
	int k;
	cin >> k;
	int c;
	cin >> c;
	vector<vector<bool>> board(n + 1, vector<bool>(n + 1));
	for (int t = 0; t < c; t++) {
		int cc;
		cin >> cc;
		vector<pr> circuit(cc);
		for (int i = 0; i < cc; i++)
			cin >> circuit[i].first >> circuit[i].second;
		for (int r = 0; r < cc - 1; r++) {
			int fx = circuit[r].first, fy = circuit[r].second;
			int lx = circuit[r + 1].first, ly = circuit[r + 1].second;
			if (fx == lx) {
				for (int i = fy; i != ly; (fy > ly ? i-- : i++))
					board[lx][i] = true;
			}
			else {
				for (int i = fx; i != lx; (fx > lx ? i-- : i++))
					board[i][ly] = true;
			}
			if (r == cc - 2)
				board[lx][ly] = true;
		}
	}
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, 987654321));
	vector<vector<pr>> prev(n + 1, vector<pr>(n + 1, { -1, -1 }));
	priority_queue<prr> pq;
	dist[sx][sy] = 1;
	pq.push({ -1, {sx, sy} });
	while (!pq.empty()) {
		int len = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (x == gx && y == gy)
			break;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx <= 0 || yy <= 0 || xx > n || yy > n)
				continue;
			int nlen = len + (board[xx][yy] ? k : 1);
			if (dist[xx][yy] > nlen) {
				dist[xx][yy] = nlen;
				prev[xx][yy] = { x, y };
				pq.push({ -nlen, {xx, yy} });
			}
		}
	}
	cout << dist[gx][gy] << '\n';
	vector<pr> res;
	res.push_back({ gx, gy });
	int dir = -1;
	int tx = prev[gx][gy].first, ty = prev[gx][gy].second;
	if (gx == tx) {
		if (gy > ty)
			dir = 3;
		else
			dir = 1;
	}
	else if (gy == ty) {
		if (gx > tx)
			dir = 0;
		else
			dir = 2;
	}
	while (true) {
		int ttx = prev[tx][ty].first, tty = prev[tx][ty].second;
		if (ttx == -1 && tty == -1) {
			res.push_back({ sx, sy });
			break;
		}
		int ndir = -1;
		if (tx == ttx) {
			if (ty > tty)
				ndir = 3;
			else
				ndir = 1;
		}
		else if (ty == tty) {
			if (tx > ttx)
				ndir = 0;
			else
				ndir = 2;
		}
		if (dir != ndir)
			res.push_back({ tx, ty });
		tx = ttx;
		ty = tty;
		dir = ndir;
	}
	reverse(res.begin(), res.end());
	cout << res.size() << ' ';
	for (pr p : res)
		cout << p.first << ' ' << p.second << ' ';
	cout << '\n';
}

// n*n 보드의 두 지점을 잇는 회로를 설치하려 하는데, 이미 회로가 놓인 곳으로 회로를 놓으면 비용이 k, 그렇지 않은 곳에 놓으면 1의 비용이 든다
// 이 상황에서 두 지점을 잇는 회로를 설치하는 최소 비용과 그 방법(시작점 - 방향 전환점(들) - 도착점) 출력하기

// 2차원 공간에서의 다익스트라 - 2차원 bfs처럼 상하좌우 네칸을 탐색하되, 가중치가 주어지는 곳으로 진입하면 추가 가중치를 주는 방식으로
// 먼저 주어진 회로 리스트를 이용해 bool 보드에 회로를 true로 깔기 - 회로는 시작점과 도착점, 그리고 방향 전환점들만 제공
// - 각 전환점을 배열화시켜서 i번째 점과 i + 1번째 점 사이의 모든 점을 true로 만들어주기, !=로 점 순회시 맨 마지막 점은 따로 찍어줘야 함
// 이렇게 회로가 찍힌 보드를 바탕으로 다익스트라 돌리기 - 2차원 공간 상이기 때문에 dist도 2차원으로 관리
// 추가로 경로 출력을 위해 dist를 갱신시킨 이전 칸을 기록하는 prev 배열도 생성 - 역시 2차원, 초기값은 {-1, -1}
// 다음 경로 탐색 시 회로가 있는 곳으로 진입한다면 가중치를 k를 주고, 그렇지 않다면 1을 주면서 다익스트라를 돌리고, 도착점에 도달하면 중지
// 이후 결과 경로를 출력하기 위해 결과 배열에 역순으로 경로 삽입 - 시작은 도착점만 넣고, 도착점 바로 전 위치를 보며 초기 진행 방향 잡기
// 이후 prev를 활용해 출발점까지 올라가면서 이전 방향과 현재 방향이 달라지면 달라지는 지점의 위치를 배열에 넣고, 도착점에 도달하면 출발점을 삽입하며 탐색 종료
// 이를 반전한 뒤 총 비용, 결과 배열 길이와 함께 출력하면 됨 - 가중치만 동일하면 아무 경로든 관계없음