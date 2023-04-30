// 점프 게임
// https://www.acmicpc.net/problem/15558

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<vector<bool>> board(n, vector<bool>(2)), visit(n, vector<bool>(2));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			board[j][i] = c == '1';
		}
	}
	bool res = false;
	queue<prr> q;
	q.push({{0, 0}, 0});
	visit[0][0] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().first.second;
		q.pop();
		if (x + 1 > t) {
			if (x + 1 >= n) {
				res = true;
				break;
			}
			if (board[x + 1][y] && !visit[x + 1][y]) {
				visit[x + 1][y] = true;
				q.push({{x + 1, y}, t + 1});
			}
		}
		if (x - 1 > t) {
			if (board[x - 1][y] && !visit[x - 1][y]) {
				visit[x - 1][y] = true;
				q.push({{x - 1, y}, t + 1});
			}
		}
		if (x + k > t) {
			if (x + k >= n) {
				res = true;
				break;
			}
			int yy = y == 0 ? 1 : 0;
			if (board[x + k][yy] && !visit[x + k][yy]) {
				visit[x + k][yy] = true;
				q.push({{x + k, yy}, t + 1});
			}
		}
	}
	cout << res << '\n';
}

// 2행로 이루어진 n열의 보드에서 일부 칸이 뚫려 있고, 1행 1열에서 시작해 n열로 이동하는 방식이 아래와 같은 상황에서 매 이동마다 왼쪽의 열부터 하나씩 없어질 때, 보드 밖으로 나갈 수 있는지 판정하기
// (같은 행에서 1칸 전진 / 1칸 후진, 다른 행으로 k칸 전진)

// bfs - 그런데 종료 지점이 맵 밖이고, 시간이 지날수록 칸이 하나씩 사라지는
// 따라서 bfs를 돌릴 때 시간도 같이 넘겨줘야 한다 - 이를 고려해서 계산