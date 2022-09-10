// HOMWRK
// https://www.acmicpc.net/problem/18398

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
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			cout << (a + b) << ' ' << (a * b) << '\n';
		}
	}
}

// 주어진 두 수의 합과 곱 구하기

// 구하면 됩니다... - 테케와 그 속의 문제 개수에 유의하며