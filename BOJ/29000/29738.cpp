// Goodbye, Code Jam
// https://www.acmicpc.net/problem/29738

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		int n;
		cin >> n;
		cout << "Case #" << t << ": ";
		if (n > 4500) {
			cout << "Round 1";
		} else if (n > 1000) {
			cout << "Round 2";
		} else if (n > 25) {
			cout << "Round 3";
		} else {
			cout << "World Finals";
		}
		cout << '\n';
	}
}

// 상위 4500명, 1000명, 25명이 각각 다음 라운드로 갈 때, 주어진 등수의 라운드 출력하기

// 범위 체크 