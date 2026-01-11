// 병영외 급식
// https://www.acmicpc.net/problem/30204

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, x;
	cin >> n >> x;
	int t = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		t += p % x;
	}
	cout << (t % x == 0) << '\n';
}

// 두 수 중 가장 큰 수 * 2를 규칙에 맞게 출력하기