// 경쟁적 전염
// https://www.acmicpc.net/problem/18405

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
typedef pair<int, int> pr;
typedef pair<int, pr> prr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<vector<int>> board(n + 1, vector<int>(n + 1));
	vector<prr> qt;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0)
				qt.push_back({ board[i][j], {i, j}});
		}
	}
	int s, tx, ty;
	cin >> s >> tx >> ty;
	sort(qt.begin(), qt.end());
	queue<prr> q;
	for (prr& p : qt)
		q.push(p);
	int qs = q.size(), sec = 0;
	while (sec < s) {
		while (qs--) {
			int p = q.front().first;
			int x = q.front().second.first;
			int y = q.front().second.second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx <= 0 || yy <= 0 || xx > n || yy > n)
					continue;
				if (board[xx][yy] == 0) {
					board[xx][yy] = p;
					q.push({ p, {xx, yy} });
				}
			}
		}
		qs = q.size();
		sec++;
	}
	cout << board[tx][ty] << '\n';
}

// 고유한 번호가 있는 바이러스가 n*n 보드에서 번호 순서대로 1초에 상하좌우 한 칸씩 증식하며 빈 칸을 채울 때, s초 뒤 [tx][ty]에 있는 바이러스의 번호는?

// 여러 개의 위치에서 시작하는 bfs 채우기 문제
// 보드 입력을 받는 동안 바이러스의 위치임이 확인되면 대기 배열에 삽입 - 입력을 마치면 해당 배열을 바이러스 번호 순으로 정렬하고 큐에 삽입
// 사실 특별한 제한 조건이 없는 bfs는 큐에 각 단계별로 차곡차곡 쌓임 - 즉, 초를 시작하기 전의 큐 크기를 기억한 후, 해당 크기만큼만 큐에서 삭제하면 초가 마무리됨
// 이를 이용하여 초 단위로 큐 연산 사용하기 - 한 바이러스가 칸을 선점하면 다른 바이러스가 접근할 수 없으므로 board와 visit를 하나로 운영할 수 있음
// 그리고 목표 초에 도달한 후 board[tx][ty]에 있는 값이 답