// 미역은 식물 아닌데요
// https://www.acmicpc.net/problem/30502

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1, -1), b(n + 1, -1);
	for (int i = 0; i < m; i++) {
		int p, t;
		char c;
		cin >> p >> c >> t;
		if (c == 'P') {
			a[p] = t;
		} else {
			b[p] = t;
		}
	}
	int resa = 0, resb = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1 && b[i] == 0) {
			resa++;
		}
		if (a[i] != 0 && b[i] != 1) {
			resb++;
		}
	}
	cout << resa << ' ' << resb << '\n';
}

// n개의 식물들의 광합성 및 운동성 여부가 제한적으로 주어질 때, 광합성을 하고 운동성이 없는 최소/최대 구하기