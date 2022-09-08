// Fridge of Your Dreams
// https://www.acmicpc.net/problem/11104

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int t = 0; t < n; t++) {
		string s;
		cin >> s;
		int res = 0;
		int p = 1 << 23;
		for (int i = 0; i < 24; i++) {
			res += (s[i] - '0') * p;
			p /= 2;
		}
		cout << res << '\n';
	}
}

// 24비트 2진수가 주어졌을 때 10진수로 변환하기

// 계속 해왔던 거니까...