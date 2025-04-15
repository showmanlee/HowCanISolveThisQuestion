// 대칭제곱수
// https://www.acmicpc.net/problem/33573

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		long long n;
		cin >> n;
		bool res = (long long)sqrt(n) == sqrt(n);
		if (res) {
			string s = to_string(n);
			reverse(s.begin(), s.end());
			long long p = stoll(s);
			res = (long long)sqrt(p) == sqrt(p);
		}
		cout << (res ? "YES" : "NO") << '\n';
	}
}

// 주어진 정수가 뒤집어도 제곱수인지 확인하기