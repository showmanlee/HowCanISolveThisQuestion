// 3대 512
// https://www.acmicpc.net/problem/33990

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 987654321;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		int sum = a + b + c;
		if (sum >= 512) {
			res = min(res, sum);
		}
	}
	if (res == 987654321) {
		res = -1;
	}
	cout << res << '\n';
}

// 주어지는 세 수들의 합 중 512 이상이면서 가장 작은 값 구하기