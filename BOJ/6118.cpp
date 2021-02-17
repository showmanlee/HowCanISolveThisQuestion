// 숨바꼭질
// https://www.acmicpc.net/problem/6118

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> board(n + 1, vector<bool>(n + 1));
	vector<int> length(n + 1, -1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = board[b][a] = true;
	}
	queue<int> q;
	q.push(1);
	length[1] = 0;
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (c != i && board[c][i] && length[i] == -1) {
				length[i] = length[c] + 1;
				q.push(i);
			}
		}
	}
	int res = 0, max = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (length[i] > max) {
			res = i;
			max = length[i];
			cnt = 1;
		}
		else if (length[i] == max)
			cnt++;
	}
	cout << res << ' ' << max << ' ' << cnt;
}

// 양방향 길로 이어진 헛간들 중 1번 헛간에서 가장 먼 헛간과 그 거리, 그리고 해당 헛간과 같은 거리에 있는 헛간의 수는?
// BFS