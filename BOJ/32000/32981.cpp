// 찐 Even Number
// https://www.acmicpc.net/problem/32981

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dq(long long a, long long b) {
	if (b == 0) {
		return 1;
	}
	long long p = dq(a, b / 2);
	long long res = (p * p) % 1000000007;
	if (b % 2 == 1) {
		res = res * a % 1000000007;
	}
	return res;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		long long n;
		cin >> n;
		long long res = 5;
		if (n > 1) {
			res = dq(5, n - 1);
			res = (res * 4) % 1000000007;
		}
		cout << res << '\n';
	}
}

// 각 자릿수가 짝수로만 이루어진 n자리 자연수의 개수 구하기