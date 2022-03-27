// 주사위 쌓기
// https://www.acmicpc.net/problem/2116

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int oposite[6] = { 5, 3, 4, 1, 2, 0 };
int candidate[6][4] = {
	{1, 2, 3, 4},
	{0, 2, 4, 5},
	{0, 1, 3, 5},
	{0, 2, 4, 5},
	{0, 1, 3, 5},
	{1, 2, 3, 4}
};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> board(n, vector<int>(6));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> board[i][j];
		}
	}
	int res = 0;
	for (int t = 0; t < 6; t++) {
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			sum = max(sum, board[0][candidate[t][i]]);
		}
		int o = oposite[t];
		for (int d = 1; d < n; d++) {
			int s = 0;
			for (int i = 0; i < 6; i++) {
				if (board[d - 1][o] == board[d][i]) {
					s = i;
				}
			}
			int p = 0;
			for (int i = 0; i < 4; i++) {
				p = max(p, board[d][candidate[s][i]]);
			}
			sum += p;
			o = oposite[s];
		}
		res = max(res, sum);
	}
	cout << res << '\n';
}

// 1~6까지가 적힌 주사위가 차례대로 주어질 때, 주사위의 맞닿는 면의 수가 동일하도록 쌓아 만든 한 옆면의 합이 최대인 경우 구하기

// 첫 주사위의 어느쪽 면을 위로 놓을지 결정하고, 이후 모든 주사위의 어느쪽 옆면을 계산에 포함할지 결정한다
// 첫 주사위의 경우를 결정하는데 6, 옆면 방향 결정하는데 4 * n - n^2도 아니므로 브포로 계산 가능
// 다음 주사위 쌓을 때 이전 주사위 윗면을 보고 어느쪽이 붙는지 보고, 그 면을 기반으로 옆면을 찾아내는 게 포인트