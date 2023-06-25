// Final Price
// https://www.acmicpc.net/problem/28224

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		res += p;
	}
	cout << res << '\n';
}

// 주어진 가격의 총합 구하기

// 그냥 모두 더하면 되는 문제