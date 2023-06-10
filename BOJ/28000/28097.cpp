// 모범생 포닉스
// https://www.acmicpc.net/problem/28097

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		res += p;
		if (i != n - 1) {
			res += 8;
		}
	}
	cout << (res / 24) << ' ' << (res % 24) << '\n';
}

// 연속으로 공부한 시간들이 주어지고 그 사이에 8시간씩 쉰다고 할 때, 총 소요시간을 일 / 시간으로 출력하기

// 계산 계산 계산