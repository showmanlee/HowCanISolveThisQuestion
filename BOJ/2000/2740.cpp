// 행렬 곱셈
// https://www.acmicpc.net/problem/2740

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, m, k;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	cin >> m >> k;
	vector<vector<int>> b(m, vector<int>(k));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++)
			cin >> b[i][j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int p = 0;
			for (int h = 0; h < m; h++) {
				p += a[i][h] * b[h][j];
			}
			cout << p << ' ';
		}
		cout << '\n';
	}
}

// 행렬 곱셈 = 한 행렬의 가로 길이, 그리고 다른 행렬의 세로 길이가 같을 때, 한 행렬의 세로 * 다른 행렬의 가로 크기로 나오는 계산
// 대학교 때 행렬을 배워서 다행이야