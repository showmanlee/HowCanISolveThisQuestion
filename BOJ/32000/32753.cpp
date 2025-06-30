// 네 또 수열입니다
// https://www.acmicpc.net/problem/32753

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	if (n == 1) {
		for (int i = 0; i < k; i++) {
			cout << 1 << ' ';
		}
	} else if (n == 2 && k == 1) {
		cout << "1 2";
	} else {
		cout << -1;
	}
	cout << '\n';
}

// 1~n이 k개 있는 수열에서, 1 <= i < n * k인 모든 i에 대해 A1 + ... Ai = i를 만족하는 수열 출력하기