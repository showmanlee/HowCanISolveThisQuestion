// Error Detection
// https://www.acmicpc.net/problem/5220

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int a, b;
		cin >> a >> b;
		int res = 0;
		while (a > 0) {
			if (a % 2 == 1) {
				res++;
			}
			a /= 2;
		}
		cout << (res % 2 == b ? "Valid" : "Corrupt") << '\n';
	}
}

// 주어진 정수의 이진수 형태에 1의 개수가 홀수인지 여부가 주어질 때, 정확한지 판정하기