// 스티커 나눠주기
// https://www.acmicpc.net/problem/33868

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int t = 0, b = 987654321;
	for (int i = 0; i < n; i++) {
		int tt, bb;
		cin >> tt >> bb;
		t = max(t, tt);
		b = min(b, bb);
	}
	int res = t * b % 7 + 1;
	cout << res << '\n';
}

// t의 최댓값과 b의 최솟값의 곱을 7로 나눈 나머지를 이용해 줘야 할 스티커의 종류 구하기