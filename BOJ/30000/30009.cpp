// 포지션 제로
// https://www.acmicpc.net/problem/30009

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	float x, y, r;
	cin >> x >> y >> r;
	int resa = 0, resb = 0;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (x - r < t && t < x + r) {
			resa++;
		} else if (t == x - r || t == x + r) {
			resb++;
		}
	}
	cout << resa << ' ' << resb << '\n';
}

// 주어진 원과 y축에 평행한 직선이 주어질 때, 원 안으로 들어가는 직선과 접하는 직선의 개수 구하기