// RSA Numbers
// https://www.acmicpc.net/problem/6872

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	int res = 0;
	for (int i = a; i <= b; i++) {
		int cnt = 2;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				cnt++;
				if (cnt > 4) {
					break;
				}
			}
		}
		if (cnt == 4) {
			res++;
		}
	}
	cout << "The number of RSA numbers between " << a << " and " << b << " is " << res << '\n';
}

// a부터 b 사이의 정수 중 약수가 4개인 수의 개수 구하기
