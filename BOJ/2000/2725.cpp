// 보이는 점의 개수
// https://www.acmicpc.net/problem/2725

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		int p = a % b;
		a = b;
		b = p;
	}
	return a;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v(1001);
	v[1] = 3;
	for (int i = 2; i <= 1000; i++) {
		int p = 0;
		for (int j = 1; j < i; j++) {
			if (gcd(i, j) == 1) {
				p++;
			}
		}
		v[i] = v[i - 1] + 2 * p;
	}

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		cout << v[n] << '\n';
	}
}

// n*n 좌표공간에서 (0,0)에서 직선을 그어 다른 점과 만나지 않고 닿을 수 있는 점의 개수는?

// 규칙을 세워보면 3, 5, 9, 13, 21...
// +2, +4, +4, +8... - 규칙적이지 않다, 다른 방식으로 구해야 한다는 것
// 점이 가려지지 않으려면 두 점을 이은 직선의 기울기가 고유해야 한다 - x와 y를 나누어떨어지게 만들 수 있는 최대공약수가 1이어야 한다는 것
// 이를 이용해 1부터 1000까지의 답을 미리 구해둘 수 있다 - v[1] = 3(01 11 10), v[i] = v[i - 1] + (2 * 고유 기울기 수)
// 고유 기울기 수에 2를 곱해주는 이유는 계산 시 x < y인 경우만 보기 때문이고, x == y일 경우 (1,1) 때문에 가려져서 누적되지 않기 때문