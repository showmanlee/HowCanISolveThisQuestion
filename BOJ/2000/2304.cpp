// 창고 다각형
// https://www.acmicpc.net/problem/2304

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> board(1001);
	for (int i = 0; i < n; i++) {
		int l, h;
		cin >> l >> h;
		board[l] = h;
	}
	vector<int> res(1001, 987654321);
	int key = 0;
	for (int i = 1; i <= 1000; i++) {
		key = max(key, board[i]);
		res[i] = min(res[i], key);
	}
	int sum = 0;
	key = 0;
	for (int i = 1000; i >= 1; i--) {
		key = max(key, board[i]);
		res[i] = min(res[i], key);
		sum += res[i];
	}
	cout << sum << '\n';
}

// 모든 기둥을 커버하면서 오목한 부분이 없게 하도록 지붕을 지을 때 바닥에서 지붕으로 구성된 다각형의 넓이는?

// 양 끝쪽에서 정점으로 갈 때 높이가 점점 높아져야 한다
// 왼쪽에서 오른쪽으로 이동하면서 높이가 계속 높아지도록 지붕을 깔고, 반대쪽으로도 돌면서 반대쪽 경사를 만든다
// 그리고 각 지점의 높이의 합이 답