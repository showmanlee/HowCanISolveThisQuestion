// 이동하기
// https://www.acmicpc.net/problem/11048

#include <iostream>
#include <string>
using namespace std;

int candies[1001][1001];

int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> candies[i][j];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int p = candies[i - 1][j - 1];
			if (p < candies[i][j - 1])
				p = candies[i][j - 1];
			if (p < candies[i - 1][j])
				p = candies[i - 1][j];
			candies[i][j] += p;
		}
	}
	cout << candies[n][m] << '\n';
}

// 좌, 하, 좌하단으로 이동할 수 있는 공간에서 사탕을 최대한으로 가져올 수 있는 수
// 2차원 dp