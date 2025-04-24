// L-트로미노 타일링
// https://www.acmicpc.net/problem/33675

#include <iostream>
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
		long long res = 0;
		if (n % 2 == 0) {
			res = 1LL << (n / 2);
		}
		cout << res << '\n';
	}
}

// 3*n 보드를 L 블럭으로 모두 채우는 경우의 수 구하기