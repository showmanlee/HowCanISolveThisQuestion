// 거울반사
// https://www.acmicpc.net/problem/25755

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	char d;
	int n;
	cin >> d >> n;
	vector<vector<char>> res(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x = (d == 'U' || d == 'D') ? n - i - 1 : i;
			int y = (d == 'L' || d == 'R') ? n - j - 1 : j;
			int p;
			cin >> p;
			if (p == 1 || p == 8) {
				res[x][y] = '0' + p;
			} else if (p == 2) {
				res[x][y] = '5';
			} else if (p == 5) {
				res[x][y] = '2';
			} else {
				res[x][y] = '?';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i][j] << ' ';
		}
		cout << '\n';
	}
}

// 주어진 숫자 2차원 보드를 주어진 방향으로 뒤집었을 때 보이는 결과 출력하기