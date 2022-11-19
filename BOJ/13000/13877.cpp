// 이건 무슨 진법이지?
// https://www.acmicpc.net/problem/13877

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int k, n;
		cin >> k >> n;
		int o = 0, d = 0, x = 0, p = 1;
		int q = n;
		while (q) {
			if (q % 10 >= 8) {
				o = 0;
				break;
			}
			o += p * (q % 10);
			p *= 8;
			q /= 10;
		}
		q = n;
		p = 1;
		while (q) {
			d += p * (q % 10);
			p *= 10;
			q /= 10;
		}
		q = n;
		p = 1;
		while (q) {
			x += p * (q % 10);
			p *= 16;
			q /= 10;
		}
		cout << k << ' ' << o << ' ' << d << ' ' << x << '\n';
	}
}

// 주어진 정수 표기를 8/10/16진수로 본 값을 10진수로 출력하기

// 여기서 8, 9가 등장한다면 8진수가 될 수 없으므로 8진수 값을 0으로 설정한다
// 그거 외에는 일반적인 나머지를 이용한 진수 변환 문제