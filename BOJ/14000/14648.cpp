// 쿼리 맛보기
// https://www.acmicpc.net/problem/14648

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	vector<long long> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int t = 0; t < q; t++) {
		int z;
		cin >> z;
		if (z == 1) {
			int a, b;
			cin >> a >> b;
			long long res = 0;
			for (int i = a; i <= b; i++) {
				res += v[i];
			}
			cout << res << '\n';
			swap(v[a], v[b]);
		} else if (z == 2) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			long long x = 0, y = 0;
			for (int i = a; i <= b; i++) {
				x += v[i];
			}
			for (int i = c; i <= d; i++) {
				y += v[i];
			}
			cout << (x - y) << '\n';
		}
	} 
}

// 주어진 수열에 대한 2가지 쿼리 수행하기