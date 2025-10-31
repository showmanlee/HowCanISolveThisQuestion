// Triple Jump
// https://www.acmicpc.net/problem/34646

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int a = v[0] / 3;
	int b = v[1] - a - a;
	int c = v[n - 1] / 3;
	cout << a << ' ' << b << ' ' << c << '\n';
}

// 정수 3개의 합으로 만든 모든 수가 나올 때, 3개의 정수 맞추기