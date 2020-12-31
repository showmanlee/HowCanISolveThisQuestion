// 경기 결과
// https://www.acmicpc.net/problem/5523

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a = 0, b = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x < y)
			b++;
		else if (x > y)
			a++;
	}
	cout << a << ' ' << b << '\n';
}

// A가 이긴 횟수와 B가 이긴 횟수 구하기
// 입력이 100만줄 주어질 수 있음에 주의