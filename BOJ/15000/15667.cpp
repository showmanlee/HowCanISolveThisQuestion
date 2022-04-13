// 2018 연세대학교 프로그래밍 경진대회
// https://www.acmicpc.net/problem/15667

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	n--;
	int res = 0;
	for (int i = 1; i <= 100; i++) {
		if (n / (i + 1) == i) {
			res = i;
			break;
		}
	}
	cout << res << '\n';
}

// 1개의 불꽃이 k개로 갈라지고, k개의 불꽃이 각각 k개로 갈라진다는 폭죽이 만드는 불꽃 개수가 주어졌을 때, k 구하기

// n = 1 + k + (k * k) = k(k + 1) + 1
// n - 1 = k(k + 1)
// (n - 1) / (k + 1) = k
// 이를 이용해서 풀어가면 된다 - n의 범위가 10101까지이므로 k는 최대 100