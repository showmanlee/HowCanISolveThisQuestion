// 색종이
// https://www.acmicpc.net/problem/2563

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<bool>> place(101, vector<bool>(101));
	for (int t = 0; t < n; t++) {
		int x, y;
		cin >> x >> y;
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				place[i][j] = true;
			}
		}
	}
	int res = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			res += place[i][j];
		}
	}
	cout << res << '\n';
}

// 100*100 격자 공간에 10*10 크기의 색종이들이 붙는 좌표가 주어질 때, 색종이가 붙은 넓이 출력하기

// 100*100은 크지 않으니 2차원 배열에서 계산해도 됩니다 - 실제로 그렇게 했고요