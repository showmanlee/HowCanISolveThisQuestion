// 제곱 수?
// https://www.acmicpc.net/problem/34027

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		bool res = (int)sqrt(p) == sqrt(p);
		cout << res << '\n';
	}
}

// 주어진 수가 완전제곱수인지 구하기