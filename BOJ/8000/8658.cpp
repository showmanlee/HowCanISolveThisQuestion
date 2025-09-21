// Liczba
// https://www.acmicpc.net/problem/8658

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i != 0) {
			a = i;
			break;
		}
	}
	for (int i = n - 1; i > 0; i--) {
		if (n % i != 0) {
			b = i;
			break;
		}
	}
	cout << a << ' ' << b << '\n';
}

// n의 약수가 아닌 가장 작은 자연수와 가장 큰 자연수 구하기