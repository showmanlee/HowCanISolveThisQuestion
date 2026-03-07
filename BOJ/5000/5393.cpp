// Collatz
// https://www.acmicpc.net/problem/5393

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
		long long n;
		cin >> n;
		long long a = n - (n / 2);
		long long b = ((n + 1) / 2) - (((n - 1) / 3 + 1) / 2);
		long long res = a + b;
		cout << res << '\n';
	}
}

// 모든 짝수는 n / 2, 홀수는 3n + 1과 연결된 라인에서 n까지를 자를때 잘리는 연결선의 개수 출력하기