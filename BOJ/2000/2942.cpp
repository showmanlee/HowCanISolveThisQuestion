// 퍼거슨과 사과
// https://www.acmicpc.net/problem/2942

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	int g = gcd(a, b);
	for (int i = 1; i <= g; i++) {
		if (a % i == 0 && b % i == 0) {
			cout << i << ' ' << (a / i) << ' ' << (b / i) << '\n';
		}
	}
}

// 정확히 동일하게 a개의 빨간 사과와 b개의 초록 사과를 나눠줄 수 있는 경우 모두 출력하기