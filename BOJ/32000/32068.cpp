// 보물 찾기
// https://www.acmicpc.net/problem/32068

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int l, r, s;
		cin >> l >> r >> s;
		int res = 1 + min(s - l, r - s) * 2;
		if (s - l >= r - s) {
			res--;
		}
		cout << res << '\n';
	}
}

// 1차원 좌표를 s에서 오른쪽 왼쪽으로 1칸씩 왔다갔다 할 때, l 또는 r에 가장 먼저 닿는 턴 수 구하기