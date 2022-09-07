// 완전 제곱수
// https://www.acmicpc.net/problem/6131

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int a = 1; a <= 500; a++) {
		for (int b = a; b <= 500; b++) {
			if (b * b - a * a == n) {
				res++;
			}
		}
	}
	cout << res << '\n';
}

// 500까지의 두 자연수 쌍 중 제곱수의 차가 n인 쌍의 개수 구하기

// 모든 경우를 직접 구해서 출력하기 