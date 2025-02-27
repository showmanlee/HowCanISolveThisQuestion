// Champernowne Verification
// https://www.acmicpc.net/problem/31520

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int v[10] = {0, 1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789};
	bool pass = false;
	for (int i = 1; i < 10; i++) {
		if (n == v[i]) {
			cout << i << '\n';
			pass = true;
			break;
		}
	}
	if (!pass) {
		cout << -1 << '\n';
	}
}

// 주어진 수가 1부터 p까지 이어지는 수일 때, p 출력하기	