// 얼마?
// https://www.acmicpc.net/problem/9325

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int res;
		cin >> res;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			res += a * b;
		}
		cout << res << '\n';
	}
}

// 차량의 가격과 장착하려는 옵션들의 개수와 가격이 주어질 때 총합 구하기

// 구하면 됩니다 - 차량의 가격을 res삼아, 주어지는 옵션들 모두 더하기