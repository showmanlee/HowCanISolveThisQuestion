// 최댓값
// https://www.acmicpc.net/problem/2566

#include <iostream>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> board(10, vector<int>(10));
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			cin >> board[i][j];

	int res = -1;
	int mx = 0, my = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (board[i][j] > res) {
				res = board[i][j];
				mx = i;
				my = j;
			}
		}
	}
	cout << res << '\n' << mx << ' ' << my << '\n';
}

// 9x9 보드에 0~100까지의 수가 적혀있을 때, 최댓값과 그 위치 출력하기

// 범위가 0~100임에 주의 - max로 잡기 위해서는 초기값을 -1로 잡아야 한다