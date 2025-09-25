// Штангист
// https://www.acmicpc.net/problem/27222

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
	int res = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (v[i] == 1 && a < b) {
			res += b - a;
		}
	}
	cout << res << '\n';
}

// 각 날짜의 훈련 여부와 근육 증감량이 주어졌을 때, 운동을 한 날의 근육 증가량 구하기