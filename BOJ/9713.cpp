// Sum of Odd Sequence
// https://www.acmicpc.net/problem/9713

#include <iostream>
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
		for (int i = 1; i <= n; i += 2)
			res += i;
		cout << res << '\n';
	}
}

// 1부터 n까지 홀수의 합 구하기

// 말 그대로 해주시면 됩니다 - 최대 100(99)까지라 반복문으로 처리 가능