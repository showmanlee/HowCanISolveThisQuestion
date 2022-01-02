// 배수 찾기
// https://www.acmicpc.net/problem/4504

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	while (true) {
		int p;
		cin >> p;
		if (p == 0) {
			break;
		}
		cout << p << " is " << (p % n == 0 ? "" : "NOT ") << "a multiple of " << n << ".\n";
	}
}

// 주어진 수가 n의 배수인지 판졍하기

// p % n?