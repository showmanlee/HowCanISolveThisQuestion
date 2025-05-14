// 시간표
// https://www.acmicpc.net/problem/33575

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector<int> v(n), f(m + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < a; i++) {
		int p;
		cin >> p;
		f[p] = 1;
	}
	for (int i = 0; i < b; i++) {
		int p;
		cin >> p;
		f[p] = -1;
	}
	int prev = -2, combo = 0;
	int res = 0;
	for (int i : v) {
		int p = f[i];
		if (f[i] == prev) {
			combo++;
		} else {
			if (prev != 0 && combo >= 3) {
				res += combo * prev;
			}
			prev = f[i];
			combo = 1;
		}
	}
	if (prev != 0 && combo >= 3) {
		res += combo * prev;
	}
	cout << res << '\n';
}

// 좋아하는 수업이나 싫어하는 수업이 연속으로 3번 이상 등장하면 연속된 수만큼 점수를 올릴 때, 주어진 시간표의 점수 구하기