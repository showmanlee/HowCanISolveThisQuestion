// 2의 보수
// https://www.acmicpc.net/problem/24389

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	unsigned int n;
	cin >> n;
	unsigned int m = ~n + 1;
	int res = 0;
	for (int i = 0; i < 32; i++) {
		if ((n >> i) % 2 != (m >> i) % 2) {
			res++;
		}
	}
	cout << res << '\n';
}

// 주어진 32비트 정수의 2의 보수를 구해서, 서로 다른 비트의 개수 구하기

// unsigned int