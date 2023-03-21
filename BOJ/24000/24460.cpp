// 특별상이라도 받고 싶어
// https://www.acmicpc.net/problem/24460

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[1025][1025];

int dfs(int x, int y, int n) {
	if (n == 1) {
		return board[x][y];
	}
	vector<int> v = {dfs(x, y, n / 2), dfs(x + n / 2, y, n / 2), dfs(x, y + n / 2, n / 2), dfs(x + n / 2, y + n / 2, n / 2)};
	sort(v.begin(), v.end());
	return v[1];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	int res = dfs(0, 0, n);
	cout << res << '\n';
}

// 2^k * 2^k 보드에서 같은 크기의 정사각형 네 개로 나누어 각 구역에서 이 규칙을 재귀적으로 적용해서 만든 4개의 숫자 중 2번째로 작은 숫자를 뽑을 때 나오는 숫자는?

// 재귀 문제 - 탐색할 좌표와 현재 폭을 인자로 받아 함수 만들기
// 중단점은 n == 1일때 - 이때는 그냥 그 수 출력
// 그렇지 않을 경우 네 개의 제귀 케이스 중 두 번째로 작은 경우 출력