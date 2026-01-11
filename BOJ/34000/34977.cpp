// 수미수열
// https://www.acmicpc.net/problem/34977

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
	bool res = false;
	for (int i = 0; i < n / 2; i++) {
		bool pass = true;
		for (int j = 0; j <= i; j++) {
			if (v[j] != v[n - i - 1 + j]) {
				pass = false;
				break;
			}
		}
		if (pass) {
			res = true;
			break;
		}
	}
	cout << (res ? "yes" : "no") << '\n';
}

// 수열에서 처음과 끝 부분 연속된 게 같을 수 있는지 구하기