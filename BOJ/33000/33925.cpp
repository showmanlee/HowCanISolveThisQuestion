// 쿠키런
// https://www.acmicpc.net/problem/33925

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, j, s, h, k;
	cin >> n >> j >> s >> h >> k;
	vector<vector<char>> board(3, vector<char>(n));
	for (int i = 0; i < 3; i++) {
		for (int ii = 0; ii < n; ii++) {
			cin >> board[i][ii];
		}
	}
	int aa = 0, bb = 0, cc = 0;
	for (int i = 0; i < n; i++) {
		if (board[1][i] == '^' && board[2][i] == '^') {
			bb++;
		} else if (board[2][i] == '^') {
			aa++;
		} else if (board[0][i] == 'v' && board[1][i] == 'v') {
			cc++;
		}
	}
	if (aa > j) {
		aa -= j;
		j = 0;
	} else {
		j -= aa;
		aa = 0;
	}
	if (bb * 2 > j) {
		aa -= j / 2;
		j = 0;
	} else {
		j -= bb * 2;
		bb = 0;
	}
	if (cc > s) {
		cc -= s;
		s = 0;
	} else {
		s -= cc;
		cc = 0;
	}
	int res = h - ((aa + bb + cc) * k);
	if (res <= 0) {
		res = -1;
	}
	cout << res << '\n';
}

// 주어진 점프와 슬라이드 횟수만으로 스테이지를 완주했을 때 남길 수 있는 체력 구하기