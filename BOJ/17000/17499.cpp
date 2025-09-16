// 수열과 시프트 쿼리
// https://www.acmicpc.net/problem/17499

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int cur = 0;
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		if (x == 1) {
			long long z;
			cin >> z;
			v[(y - 1 + cur) % n] += z;
		} else if (x == 2) {
			cur -= y;
			while (cur < 0) {
				cur += n;
			}
		} else if (x == 3) {
			cur += y;
		}
		cur %= n;
	}
	for (int i = 0; i < n; i++) {
		cout << v[(i + cur) % n] << ' ';
	}
	cout << '\n';
}

// 주어진 수열의 특정 원소에 값을 더하거나 좌우로 시프트한 결과 출력하기