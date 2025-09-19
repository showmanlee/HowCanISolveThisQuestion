// 선물
// https://www.acmicpc.net/problem/1166

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout << fixed;
    cout.precision(16);

	long long n, l, w, h;
	cin >> n >> l >> w >> h;
	long double left = 0, right = 10000000000;
	for (int i = 0; i < 1000; i++) {
		long double mid = (left + right) / 2;
		if (floor(l / mid) * floor(w / mid) * floor(h / mid) < n) {
			right = mid;
		} else {
			left = mid;
		}
	}

	cout << left << '\n';
}

// l*w*h 상자에 n개를 담을 수 있는 정사각형 상자의 변 길이 최댓값 구하기