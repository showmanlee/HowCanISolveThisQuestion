// Automated Telephone Exchange
// https://www.acmicpc.net/problem/3507

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			if (i + j == n) {
				res++;
			}
		}
	}
	cout << res << '\n';
}

// 주어진 세자릿수에서 두자릿수 2개를 빼서 0으로 만들 수 있는 두자릿수 쌍의 개수 구하기

// 직접 돌려보면서 구해도 상관없음