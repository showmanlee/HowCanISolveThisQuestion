// 2048 (Easy)
// https://www.acmicpc.net/problem/12100

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int origin[21][21];
int dir[5];
int res;

int calculate() {
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[i][j] = origin[i][j];
	for (int t = 0; t < 5; t++) {
		switch (dir[t]) {
			case 0:
				for (int i = 0; i < n; i++) {
					queue<int> q;
					for (int j = 0; j < n; j++) {
						if (board[i][j] != 0)
							q.push(board[i][j]);
						board[i][j] = 0;
					}
					int idx = 0;
					while (!q.empty()) {
						if (board[i][idx] == 0) {
							board[i][idx] = q.front();
						}
						else if (board[i][idx] == q.front()) {
							board[i][idx] += q.front();
							idx++;
						}
						else {
							idx++;
							board[i][idx] = q.front();
						}
						q.pop();
					}
				}
				break;
			case 1:
				for (int i = 0; i < n; i++) {
					queue<int> q;
					for (int j = 0; j < n; j++) {
						if (board[j][i] != 0)
							q.push(board[j][i]);
						board[j][i] = 0;
					}
					int idx = 0;
					while (!q.empty()) {
						if (board[idx][i] == 0) {
							board[idx][i] = q.front();
						}
						else if (board[idx][i] == q.front()) {
							board[idx][i] += q.front();
							idx++;
						}
						else {
							idx++;
							board[idx][i] = q.front();
						}
						q.pop();
					}
				}
				break;
			case 2:
				for (int i = 0; i < n; i++) {
					queue<int> q;
					for (int j = n - 1; j >= 0; j--) {
						if (board[i][j] != 0)
							q.push(board[i][j]);
						board[i][j] = 0;
					}
					int idx = n - 1;
					while (!q.empty()) {
						if (board[i][idx] == 0) {
							board[i][idx] = q.front();
						}
						else if (board[i][idx] == q.front()) {
							board[i][idx] += q.front();
							idx--;
						}
						else {
							idx--;
							board[i][idx] = q.front();
						}
						q.pop();
					}
				}
				break;
			case 3:
				for (int i = 0; i < n; i++) {
					queue<int> q;
					for (int j = n - 1; j >= 0; j--) {
						if (board[j][i] != 0)
							q.push(board[j][i]);
						board[j][i] = 0;
					}
					int idx = n - 1;
					while (!q.empty()) {
						if (board[idx][i] == 0) {
							board[idx][i] = q.front();
						}
						else if (board[idx][i] == q.front()) {
							board[idx][i] += q.front();
							idx--;
						}
						else {
							idx--;
							board[idx][i] = q.front();
						}
						q.pop();
					}
				}
				break;
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ret = max(ret, board[i][j]);
	return ret;
}

void move(int p) {
	if (p == 5) {
		res = max(res, calculate());
		return;
	}
	for (int i = 0; i < 4; i++) {
		dir[p] = i;
		move(p + 1);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> origin[i][j];
	res = 0;
	move(0);
	cout << res << '\n';
}

// 2048 게임에서 보드가 주어졌을 때, 5번 움직여서 얻을 수 있는 가장 높은 블록은?
// 기본적으로 브루트포스로 이동할 방향을 결정 - 그런데 합쳐지는 걸 어떻게 구현할까?

// 다양한 방법이 있겠지만, 각 방향별로 큐를 이용할 수도 있음
// 각 방향의 칸들을 한 번씩 순회하면서 0이 아니면 해당 숫자를 큐에 넣고 0으로 바꾼다
// 이후 각 방향으로 진행하면서 빈칸을 발견하면 큐의 숫자를 넣고,
// 해당 칸이 큐의 숫자와 같다면 거기에 큐의 숫자를 추가한 후 한 칸 전진하고, 다르다면 한 칸 전진해서 거기에 큐의 숫자를 넣는다
// 이 과정을 5번 반복한 후, 모든 칸을 순회하며 최댓값 뽑아내기