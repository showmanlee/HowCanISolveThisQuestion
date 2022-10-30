// 2,147,483,648 게임
// https://www.acmicpc.net/problem/23796

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<vector<unsigned int>> board(8, vector<unsigned int>(8)), res(8, vector<unsigned int>(8));
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> board[i][j];
		}
	}
	char c;
	cin >> c;
	if (c == 'U') {
		for (int j = 0; j < 8; j++) {
			int idx = 0;
			queue<unsigned int> q;
			for (int i = 0; i < 8; i++) {
				if (board[i][j] != 0) {
					q.push(board[i][j]);
				}
			}
			while (!q.empty()) {
				unsigned int p = q.front();
				q.pop();
				if (res[idx][j] == 0) {
					res[idx][j] = p;
				} else if (res[idx][j] == p) {
					res[idx][j] += p;
					idx++;
				} else {
					idx++;
					res[idx][j] = p;
				}
			}
		}
	} else if (c == 'D') {
		for (int j = 0; j < 8; j++) {
			int idx = 7;
			queue<unsigned int> q;
			for (int i = 7; i >= 0; i--) {
				if (board[i][j] != 0) {
					q.push(board[i][j]);
				}
			}
			while (!q.empty()) {
				unsigned int p = q.front();
				q.pop();
				if (res[idx][j] == 0) {
					res[idx][j] = p;
				} else if (res[idx][j] == p) {
					res[idx][j] += p;
					idx--;
				} else {
					idx--;
					res[idx][j] = p;
				}
			}
		}
	} else if (c == 'L') {
		for (int i = 0; i < 8; i++) {
			int idx = 0;
			queue<unsigned int> q;
			for (int j = 0; j < 8; j++) {
				if (board[i][j] != 0) {
					q.push(board[i][j]);
				}
			}
			while (!q.empty()) {
				unsigned int p = q.front();
				q.pop();
				if (res[i][idx] == 0) {
					res[i][idx] = p;
				} else if (res[i][idx] == p) {
					res[i][idx] += p;
					idx++;
				} else {
					idx++;
					res[i][idx] = p;
				}
			}
		}
	} else if (c == 'R') {
		for (int i = 0; i < 8; i++) {
			int idx = 7;
			queue<unsigned int> q;
			for (int j = 7; j >= 0; j--) {
				if (board[i][j] != 0) {
					q.push(board[i][j]);
				}
			}
			while (!q.empty()) {
				unsigned int p = q.front();
				q.pop();
				if (res[i][idx] == 0) {
					res[i][idx] = p;
				} else if (res[i][idx] == p) {
					res[i][idx] += p;
					idx--;
				} else {
					idx--;
					res[i][idx] = p;
				}
			}
		}		
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << res[i][j] << ' ';
		}
		cout << '\n';
	}
}

// 8*8 2048 보드판에서 현재 상태와 누를 방향키가 주어질 때, 다음 상태 출력하기

// 이미 우리는 12100번 문제에서 2048 보드를 시뮬레이션해본 적이 있음
// 이를 이용해 한 번만 시뮬레이션 해보면 됩니다
// 2,147,483,648는 int 범위를 벗어남에 주의