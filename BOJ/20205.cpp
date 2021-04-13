// 교수님 그림이 깨지는데요?
// https://www.acmicpc.net/problem/20205

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<vector<int>> board(n * k, vector<int>(n * k));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i * k][j * k];
			for (int p = 0; p < k; p++)
				for (int q = 0; q < k; q++)
					board[i * k + p][j * k + q] = board[i * k][j * k];
		}
	}
	for (int i = 0; i < n * k; i++) {
		for (int j = 0; j < n * k; j++)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
}

// n*n 비트맵 이미지를 k배 업샘플링하기
// 결국 n*n의 각 픽셀을 k*k로 키우는 것
// n^2 * k^2 반복문 노가다 - 보드는 하나로 줄일 수 있음
