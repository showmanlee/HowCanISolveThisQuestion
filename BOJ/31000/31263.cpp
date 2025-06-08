// 대한민국을 지키는 가장 긴 힘
// https://www.acmicpc.net/problem/31263

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string s;
	cin >> n >> s;
	int pos = 0, res = 0;
	while (pos < n) {
		res++;
		int len = min(3, n - pos);
		while (true) {
			int p = s[pos] - '0';
			if (p == 0) {
				pos--;
				len = min(3, n - pos);
				continue;
			}
			for (int i = 1; i < len; i++) {
				p = p * 10 + (s[pos + i] - '0');
			}
			if (p <= 641) {
				pos += len;
				break;
			} else {
				len--;
			}
		}
	}
	cout << res << '\n';
}

// 1~641을 이어 붙여 만든 정수에서 가능한 최소 구성 수 구하기