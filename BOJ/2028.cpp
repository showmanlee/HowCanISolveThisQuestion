// 자기복제수
// https://www.acmicpc.net/problem/2028

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		int p = n * n;
		bool res = false;
		if (n <= 9) {
			res = p % 10 == n;
		}
		else if (n <= 99) {
			res = p % 100 == n;
		}
		else if (n <= 999) {
			res = p % 1000 == n;
		}
		else {
			res = p % 10000 == n;
		}
		cout << (res ? "YES" : "NO") << '\n';
	}
}

// 어떤 수를 제곱했을 때 맨 뒤에 어떤 수가 그대로 나오는지 판정하기

// 입력된 수의 길이에 따라 제곱 결과의 mod 결과와 원래 수가 일치하는지 확인