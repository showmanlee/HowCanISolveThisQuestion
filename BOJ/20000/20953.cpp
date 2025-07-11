// 고고학자 예린
// https://www.acmicpc.net/problem/20953

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		long long a, b;
		cin >> a >> b;
		long long res = ((a + b) * (a + b - 1)) * (a + b) / 2;
		cout << res << '\n';
	}
}

// 1부터 a+b까지를 더한 걸 a+b번 곱한 결과 출력하기	