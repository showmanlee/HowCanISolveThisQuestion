// 최고의 맛집을 찾아서
// https://www.acmicpc.net/problem/34874

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));
	vector<int> maxx(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			maxx[i] = max(maxx[i], board[i][j]);
		}
	}
	vector<int> res(m);
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (board[i][j] < maxx[i]) {
				res[j]++;
			}
		}
	}
	for (int j = 0; j < m; j++) {
		cout << res[j] << ' ';
	}
	cout << '\n';
}

// 주어진 식당 리스트 중 모두의 최고점을 이끌어내기 위해 바꿔야 하는 점수의 갯수 구하기