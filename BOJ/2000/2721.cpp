// 삼각수의 합
// https://www.acmicpc.net/problem/2721

#include <iostream>
#include <string>
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
		int res = 0;
		for (int i = 1; i <= n; i++) {
			int p = 0;
			for (int j = 1; j <= i + 1; j++) {
				p += j;
			}
			res += i * p;
		}
		cout << res << '\n';
	}
}

// T(n)이 1부터 n까지의 합일 때, W(n) = Sum[k=1..n; k*T(k+1)] 구하기

// 단순히 1부터 n까지의 삼각수 합을 구하는 게 아님
// 1부터 n까지 T(k + 1) * k를 구하는 문제
// 따라서 이를 이해하며 반복문을 돌리면 해결