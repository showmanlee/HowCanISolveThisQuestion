// Generalized FizzBuzz
// https://www.acmicpc.net/problem/32801

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a, b;
	cin >> n >> a >> b;
	int resf = 0, resb = 0, resfb = 0;
	for (int i = 1; i <= n; i++) {
		if (i % a == 0 && i % b == 0) {
			resfb++;
		} else if (i % a == 0) {
			resf++;
		} else if (i % b == 0) {
			resb++;
		}
	}
	cout << resf << ' ' << resb << ' ' << resfb << '\n';
}

// fizzbuzz를 임의의 수 a, b로 1부터 n까지 한 결과 출력하기