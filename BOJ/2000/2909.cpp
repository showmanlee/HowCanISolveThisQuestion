// 캔디 구매
// https://www.acmicpc.net/problem/2909

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	if (k == 0) {
		cout << n << '\n';
		return 0;
	}
	int m = pow(10, k);
	int p = n % m;
	n = n / m * m;
	if (p >= m / 2) {
		n += m;
	}
	cout << n << '\n';
}

// n과 k가 주어질 때, n을 10^k에서 반올림하기

// 반올림 해줍시다
// 단 k == 0 -> 1에서 반올림할 경우에는 그냥 그대로 출력하기