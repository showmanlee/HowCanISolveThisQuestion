// João João
// https://www.acmicpc.net/problem/34778

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> v(5);
	int res = 4;
	for (int i = 0; i < 10; i++) {
		int p;
		cin >> p;
		if (!v[p]) {
			v[p] = true;
			res--;
		}
	}
	cout << res << '\n';
}

// 10개의 1~4가 등장할 때, 빠진 숫자의 개수 구하기