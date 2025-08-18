// 수열의 합
// https://www.acmicpc.net/problem/1024

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, l;
	cin >> n >> l;
	int resa = -1, resb = -1;
	for (int i = l; i <= 100; i++) {
		int t = (i - 1) * i / 2;
		if ((n - t) / i >= 0 && (n - t) % i == 0) {
			resa = (n - t) / i;
			resb = i;
			break;
		}
	}
	if (resa < 0) {
		cout << -1;
	} else {
		for (int i = 0; i < resb; i++) {
			cout << (resa + i) << ' ';
		}
	}
	cout << '\n';
}

// 합이 n인 길이 l 이상의 연속 수열 구하기