// 최댓값
// https://www.acmicpc.net/problem/2566

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

	int res = 0;
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

// 자연수가 적힌 9*9 보드에서 가장 큰 값과 그 값이 적힌 위치 출력하기
// 일반적인 방법으로 최댓값을 찾으면서 최댓값 갱신 시 위치도 갱신해주기