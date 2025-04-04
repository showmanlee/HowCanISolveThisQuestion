// ИЗРАЗ
// https://www.acmicpc.net/problem/24348

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<long long> v(3);
	cin >> v[0] >> v[1] >> v[2];
	sort(v.begin(), v.end());
	long long res = 0;
	do {
		long long a = v[0] + v[1] - v[2];
		long long b = v[0] + v[1] * v[2];
		long long c = v[0] - v[1] + v[2];
		long long d = v[0] - v[1] * v[2];
		long long e = v[0] * v[1] + v[2];
		long long f = v[0] * v[1] - v[2];
		res = max(res, max(max(a, b), max(max(c, d), max(e, f))));
	} while (next_permutation(v.begin(), v.end()));
	cout << res << '\n';
}

// 주어진 세 정수의 순서를 바꾸고 연산자를 넣어서 만들 수 있는 가장 큰 수 구하기