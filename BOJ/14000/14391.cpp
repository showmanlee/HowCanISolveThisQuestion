// 종이 조각
// https://www.acmicpc.net/problem/14391

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			board[i][j] -= '0';
		}
	}
	int res = 0;
	for (int t = 0; t < (1 << (n * m)); t++) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int p = 0;
			for (int j = 0; j < m; j++) {
				if ((t & (1 << (i * m + j))) == 0) {
					p *= 10;
					p += board[i][j];
				} else {
					sum += p;
					p = 0;
				}
			}
			sum += p;
		}
		for (int j = 0; j < m; j++) {
			int p = 0;
			for (int i = 0; i < n; i++) {
				if ((t & (1 << (i * m + j))) != 0) {
					p *= 10;
					p += board[i][j];
				} else {
					sum += p;
					p = 0;
				}
			}
			sum += p;
		}
		res = max(res, sum);
	}
	cout << res << '\n';
}

// 한 칸에 숫자 하나가 적인 최대 4*4 보드를 폭이 1이 되도록 여러 조각으로 나눌 때 조각에 적힌 수들의 합으로 얻을 수 있는 최댓값은?

// 폭이 1이라면 어느 방향으로 얼만큼 잘라도 관계가 없음 - 이럴 경우에는 조각 단위가 아닌 가로/세로 참여 범위로 보는 게 맞음
// 마침 2^16이면 브루트포스로도 가능함 - 따라서 보드에 가로 방향 조각 칸이면 0, 세로면 1을 적는다고 가정해보자
// 이후 각 방향으로 칸들을 순회하면서 방향의 칸 만나면 수에 누적시키고, 아닌 칸을 만나면 지금까지 누적시킨 수를 더해준다
// 이 과정을 반복하며 최댓값 구하기