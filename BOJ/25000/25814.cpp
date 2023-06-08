// Heavy Numbers
// https://www.acmicpc.net/problem/25814

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	int aa = 0, bb = 0;
	int ad = 0, bd = 0;
	while (a > 0) {
		ad++;
		aa += a % 10;
		a /= 10;
	}
	while (b > 0) {
		bd++;
		bb += b % 10;
		b /= 10;
	}
	aa *= ad;
	bb *= bd;
	cout << (aa > bb ? 1 : aa == bb ? 0 : 2) << '\n';
}

// 두 정수가 주어질 때, (자릿수 길이) * (각 자릿수의 합)이 더 큰 쪽 구하기

// 직접 계산해서 풀어봅니다