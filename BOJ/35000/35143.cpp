// 2026
// https://www.acmicpc.net/problem/35143

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	if (n == 1) {
		cout << 1906 << '\n';
	} else {
		string s;
		for (int i = 0; i < n; i++) {
			if (i == 0 || i == n - 1) {
				s += '1';
			} else if (i == n / 2) {
				s += '2';
			} else {
				s += '0';
			}
		}
		if (n <= 7) {
			s = to_string(stoi(s) + 1905);
		} else {
			s = s.substr(0, n - 4) + "1906";
		}
		cout << s << '\n';
	}
}

// n의 자리 자연수 중 그 자체로 팰린드롬이고 제곱과 제곱근도 팰린드롬인 가장 작은 수에 1905를 더한 결과 출력하기