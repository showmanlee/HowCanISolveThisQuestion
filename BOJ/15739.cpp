// 매직스퀘어
// https://www.acmicpc.net/problem/15739

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	vector<bool> check(n * n + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			check[board[i][j]] = true;
		}
	}
	int target = n * (n * n + 1) / 2;
	bool res = true;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++)
			sum += board[i][j];
		if (sum != target)
			res = false;
		sum = 0;
		for (int j = 0; j < n; j++)
			sum += board[j][i];
		if (sum != target)
			res = false;
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += board[i][i];
	if (sum != target)
		res = false;
	sum = 0;
	for (int i = 0; i < n; i++)
		sum += board[i][n - i - 1];
	if (sum != target)
		res = false;
	for (int i = 1; i <= n * n; i++)
		if (!check[i])
			res = false;
	cout << (res ? "TRUE" : "FALSE") << '\n';
}

// 마방진 판별하기
// 들어간 숫자가 1~n*n인 마방진의 각 줄의 합은 n(n^2 + 1) / 2이라고 함
// 이 값에 각 행, 열, 대각선의 합이 일치하는지 확인
// 추가로 숫자 중복도 확인해야 함