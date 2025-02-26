// 2025는 무엇이 특별할까?
// https://www.acmicpc.net/problem/33541

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = -1;
	for (int i = n + 1; i <= 9999; i++) {
		int a = i / 100;
		int b = i % 100;
		int p = (a + b) * (a + b);
		if (i == p) {
			res = i;
			break;
		}
	}
	cout << res << '\n';
}

// 4자리 자연수 abcd에 대해 (ab + cd)^2 == abcd가 되는 다음 수 구하기