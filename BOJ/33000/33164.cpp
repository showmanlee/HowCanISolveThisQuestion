// どら焼き (Dorayaki)
// https://www.acmicpc.net/problem/33164

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			res += (a[i] + b[j]) * max(a[i], b[j]);
		}
	}
	cout << res << '\n';
}

// 두 배열의 모든 원소쌍에 대해 두 원소의 합 * (두 원소 중 큰값)의 합 구하기