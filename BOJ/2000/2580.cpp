// 스도쿠
// https://www.acmicpc.net/problem/2580

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int board[9][9];
int n;
pr target[81];
bool clear = false;

bool check(int x, int y) {
	for (int i = 0; i < 9; i++) {
		if (board[x][i] == board[x][y] && i != y) {
			return false;
		}
		if (board[i][y] == board[x][y] && i != x) {
			return false;
		}
	}
	int xx = x / 3;
	int yy = y / 3;
	for (int i = xx * 3; i < xx * 3 + 3; i++) {
		for (int j = yy * 3; j < yy * 3 + 3; j++) {
			if (board[i][j] == board[x][y] && (i != x || j != y)) {
				return false;
			}
		}
	}
	return true;
}

void dfs(int p) {
	if (p == n) {
		clear = true;
		return;
	}
	int x = target[p].first;
	int y = target[p].second;
	for (int i = 1; i <= 9; i++) {
		board[x][y] = i;
		if (check(x, y)) {
			dfs(p + 1);
		}
		if (clear) {
			return;
		}
	}
	board[x][y] = 0;
}

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				target[n] = {i, j};
				n++;
			}
		}
	}
	dfs(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << ' ';
		}        
        cout << '\n';
    }
}

// 스도쿠 판이 주어질 때, 모두 풀기

// 세 가지 범위에서 중복 체크하면서 백트래킹으로 풀기
// 채우고 체크하는 타이밍에 유의