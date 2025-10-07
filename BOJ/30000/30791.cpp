// gahui and sousenkyo 1
// https://www.acmicpc.net/problem/30791

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v(5);
	for (int i = 0; i < 5; i++) {
		cin >> v[i];
	}
	int res = 0;
	for (int i = 1; i < 5; i++) {
		if (v[0] - v[i] <= 1000) {
			res++;
		}
	}
	cout << res << '\n';
}

// 첫번째 수와 나머지 수의 차가 1000 이하인 경우의 수 구하기