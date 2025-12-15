// 벼락치기
// https://www.acmicpc.net/problem/25373

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n;
	cin >> n;
	long long res = 0;
	if (n > 28) {
		res = (n - 29) / 7 + 8;
	} else {
		int p = 0;
		for (int i = 1; i <= 7; i++) {
			p += i;
			if (n <= p) {
				res = i;
				break;
			}
		}
	}
	cout << res << '\n';
}

// n개의 영상을 7일 동안 보는데 다음 날 보는 영상이 항상 전날 본 영상보다 적을 때, 시작하는 날 봐야 하는 영상 개수 구하기