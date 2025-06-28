// 기술 연계마스터 임스
// https://www.acmicpc.net/problem/25497

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string r;
	cin >> n >> r;
	int l = 0, s = 0;
	int res = 0;
	for (char c : r) {
		if (isdigit(c)) {
			res++;
		} else if (c == 'L') {
			l++;
		} else if (c == 'S') {
			s++;
		} else if (c == 'R') {
			l--;
			if (l < 0) {
				break;
			}
			res++;
		} else if (c == 'K') {
			s--;
			if (s < 0) {
				break;
			}
			res++;
		}
	}
	cout << res << '\n';
}

// 주어진 문자열에서 R/K를 처리하기 위해서 L/S가 선행되어야 할때, 처리되는 문자 수 구하기