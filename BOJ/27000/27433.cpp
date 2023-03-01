// 팩토리얼 2
// https://www.acmicpc.net/problem/27433

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	long long res = 1;
	for (int i = 1; i <= n; i++) {
		res *= i;
	}
	cout << res << '\n';
}

// n(0~20)! 구하기

// long long으로 계산해서 구하기