// Shifty Sum
// https://www.acmicpc.net/problem/14682

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n, k;
	cin >> n >> k;
	long long res = n;
	long long p = n;
	for (int i = 0; i < k; i++) {
		p *= 10;
		res += p;
	}
	cout << res << '\n';
}

// n과 n을 0~k번 붙인 수를 더한 결과 출력하기