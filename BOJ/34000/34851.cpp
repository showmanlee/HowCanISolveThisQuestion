// 사칙연산 게임
// https://www.acmicpc.net/problem/34851

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	long long res;
	cin >> res;
	for (int i = 0; i < n; i++) {
		long long p;
		cin >> p;
		if ((i == 0 && res == 1) || p == 1) {
			res += p;
		} else {
			res *= p;
		}
		res %= 1000000007;
	}
	cout << res << '\n';
}

// 주어진 수들 사이 연산자를 넣고 앞에서부터 계산해서 얻을 수 있는 최댓값 구하기