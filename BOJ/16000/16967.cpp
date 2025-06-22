// 배열 복원하기
// https://www.acmicpc.net/problem/16967

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int h, w, x, y;
	cin >> h >> w >> x >> y;
	vector<vector<int>> b(h + x, vector<int>(w + y));
	for (int i = 0; i < h + x; i++) {
		for (int j = 0; j < w + y; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = x; i < h; i++) {
		for (int j = y; j < w; j++) {
			b[i][j] -= b[i - x][j - y];
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << b[i][j] << ' ';
		}
		cout << '\n';
	}
}

// h*w 배열 a를 아래로 x, 오른쪽으로 y 옴겨 더해서 만든 b를 보고 배열 a 구하기