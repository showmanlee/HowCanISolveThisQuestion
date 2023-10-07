// 자리배정
// https://www.acmicpc.net/problem/10157

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> v(m + 2, vector<int>(n + 2));
	for (int i = 0; i < n + 2; i++) {
		v[0][i] = v[m + 1][i] = 987654321;
	}
	for (int i = 0; i < m + 2; i++) {
		v[i][0] = v[i][n + 1] = 987654321;
	}
	if (k > n * m) {
		cout << 0 << '\n';
	} else {
		int x = 0, y = 1;
		int d = 0;
		for (int t = 1; t <= k; t++) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (v[xx][yy] != 0) {
				d = (d + 1) % 4;
				xx = x + dx[d];
				yy = y + dy[d];
			}
			v[xx][yy] = t;
			x = xx;
			y = yy;
		}
		cout << y << ' ' << x << '\n';
	}
}

// n*m 보드의 (1,1)부터 나선형으로 번호를 채울 때, 해당 번호가 어디에 있는지 판정하기

// 직접 채워서 구해볼 수 있음