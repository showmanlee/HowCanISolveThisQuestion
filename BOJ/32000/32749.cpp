// 타노수
// https://www.acmicpc.net/problem/32749

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, t;
	cin >> n >> t;
	string s;
	cin >> s;
	int p = pow(2, n - t);
	int m = pow(2, n);
	int idx = 0;
	string res = "";
	while (idx < m) {
		string ss;
		for (int i = 0; i < p; i++) {
			ss += s[idx];
			idx++;
		}
		if (res <= ss) {
			res = ss;
		}
	}
	cout << res << '\n';
}

// 2^n자리 수를 절반으로 k번 나눠 얻을 수 있는 가장 큰 수 구하기