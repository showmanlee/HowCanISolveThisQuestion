// Andando no tempo
// https://www.acmicpc.net/problem/13580

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v(3);
	for (int i = 0; i < 3; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	bool res = false;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			for (int k = -1; k <= 1; k++) {
				if (i == 0 && j == 0 && k == 0) {
					continue;
				}
				if ((v[0] * i) + (v[1] * j) + (v[2] * k) == 0) {
					res = true;
				}
			}
		}
	}
	cout << (res ? "S" : "N") << '\n';
}

// 세 수를 최대 1번씩만 사용해서 더하고 빼서 0을 만들 수 있는지 구하기