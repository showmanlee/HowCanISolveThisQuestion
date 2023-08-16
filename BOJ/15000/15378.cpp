// 뒤집기
// https://www.acmicpc.net/problem/15738

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, k, m;
	cin >> n >> k >> m;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
	}
	for (int t = 0; t < m; t++) {
		int p;
		cin >> p;
		if (p > 0 && p < k) {
			continue;
		}
        if (p < 0 && n + p + 1 > k) {
			continue;
		}
        k = (p > 0 ? p - k + 1 : 2 * n - k + p + 1);
	}
	cout << k << '\n';
}

// 주어진 배열에서 처음/끝에서 몇 칸 범위를 뒤집는 연산을 반복할 때, 특정 인덱스가 최종적으로 어디로 가는지 확인하기

// 배열 값을 넣는 부분이 있긴 하지만, 어차피 우리는 인덱스를 보고자 하는 것
// 따라서 배열 값에는 신경쓰지 말고 인덱스만 보면 되는데 - 사실 배열을 직접 만들 필요도 없음
// 뒤집은 위치가 어디인지만 계산하고, 그대로 옮겨주면 됨