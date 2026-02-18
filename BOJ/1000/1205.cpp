// 등수 구하기
// https://www.acmicpc.net/problem/1205

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k, p;
	cin >> n >> k >> p;
	vector<int> v(p + 1, -1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	int cnt = 0, res = 1;
	for (int i = 1; i <= n; i++) {
		if (k < v[i]) {
			res++;
		} else if (k > v[i]) {
			break;
		}
		cnt++;
	}
	if (cnt == p) {
		res = -1;
	}
	cout << res << '\n';
}

// 사이즈가 n인 랭킹 보드에서 k점이 들어갈 등수 구하기