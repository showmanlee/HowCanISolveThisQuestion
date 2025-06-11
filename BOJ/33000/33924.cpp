// 신묘마루의 요술망치
// https://www.acmicpc.net/problem/33924

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	string s;
	cin >> n >> m >> k >> s;
	for (char c : s) {
		if (c == 'A') {
			n += (n <= 2 ? 2 : -2);
		} else if (c == 'B') {
			n += (n % 2 == 1 ? 1 : -1);
			m = (m == 1 ? 2 : 1);
		} else if (c == 'C') {
			n = 5 - n;
			m = (m == 1 ? 2 : 1);
		} else if (c == 'D') {
			if (m == 1) {
				if (n == 1) {
					m = 2;
				} else {
					n--;
				}
			} else {
				if (n == 4) {
					m = 1;
				} else {
					n++;
				}
			}
		}
	}
	cout << n << ' ' << m << '\n';
}

// 4*2 보드에서 주어진 명령대로 위치를 바꿀 때 이동한 결과 출력하기