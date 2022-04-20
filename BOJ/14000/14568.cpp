// 2017 연세대학교 프로그래밍 경시대회
// https://www.acmicpc.net/problem/14568

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int a = 1; a <= n; a++) {
		for (int b = a + 2; b <= n - 2; b++) {
			int c = (n - a - b);
			if (c > 0 && c % 2 == 0) {
				res++;
			}
		}
	}
	cout << res << '\n';
}

// 사탕 n개를 모두 하나 이상씩 나눠갖되 b는 a보다 2개 이상을 더 가지고 c가 가지는 양이 짝수인 경우의 수는?

// 사탕이 100개까지라 100^3으로 돌려볼 수도 있겠으나, 100^2, 어쩌면 그 아래로도 가능함
// a가 정해지면 자동으로 b의 시작 지점도 정해지고, 그에 따라 c도 결졍된다