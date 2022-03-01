// 받아올림
// https://www.acmicpc.net/problem/4388

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		long long a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) {
			break;
		}
		if (a < b) {
			swap(a, b);
		}
		int res = 0;
		int t = 0;
		while (a != 0 || b != 0) {
			if (a % 10 + b % 10 + t >= 10) {
				res++;
				t = 1;
			}
			else {
				t = 0;
			}
			a /= 10;
			b /= 10;
		}
		cout << res << '\n';
	}
}

// 두 정수를 더할 때 발생하는 받아올림 횟수는?

// 두 정수를 받은 뒤 전통적인 방식으로 더해가면 됨 - 받아올림은 별도의 변수가 담당하는 방식으로
// 수 하나에 더하는 방식은 1 + 99와 같은 케이스에서 연속으로 받아올림이 발생할 때 인식되지 않음에 주의