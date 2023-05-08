// 반올림
// https://www.acmicpc.net/problem/4539

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		if (n < 10) {
			cout << n << '\n';
			continue;
		}
		int idx = 10;
		while (n >= idx) {
			int p = n % idx;
			if (p >= idx / 10 * 5) {
				n += idx;
			}
			n -= p;
			idx *= 10;
		}
		cout << n << '\n';
	}
}

// 주어진 정수가 10 이상일 때 첫 자리까지 반올림한 결과 출력하기

// 뒷자리부터 차근차근 올라가줘야 함 - 마지막 바로 뒤를 보면 안 됨