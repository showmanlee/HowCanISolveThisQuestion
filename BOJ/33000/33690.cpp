// 포린드롬
// https://www.acmicpc.net/problem/33690

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 1;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			int a = 0;
			for (int k = 0; k < j; k++) {
				a *= 10;
				a += i;
			}
			if (a <= n) {
				res++;
			}
		}
	}
	cout << res << '\n';
}

// 주어진 수 이하의 그 자체 또는 10으로 나눈 값이 모두 팰린드롬인 수의 개수 구하기