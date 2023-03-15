// Oddities
// https://www.acmicpc.net/problem/10480

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		cout << n << " is " << (n % 2 == 0 ? "even" : "odd") << '\n';
	}
}

// 주어진 수가 홀수인지 짝수인지 판정하기

// n % 2 == ???