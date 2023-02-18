// 三方比較 (Three-Way Comparison)
// https://www.acmicpc.net/problem/27328

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	cout << (a < b ? -1 : a > b ? 1 : 0) << '\n';
}

// 두 수의 대소관게 출력하기

// 출력하시면 됩니다 - 왼쪽이 작으면 -1, 오른쪽이 작으면 1