// 서로소 평균
// https://www.acmicpc.net/problem/21920

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		int p = a % b;
		a = b;
		b = p;
	}
	return a;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int x;
	cin >> x;
	double res = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (gcd(x, v[i]) == 1) {
			res += v[i];
			cnt++;
		}
	}
	res /= cnt;
	cout << res << '\n';
}

// n개의 자연수 중 x와 서로소인 수들의 평균 구하기