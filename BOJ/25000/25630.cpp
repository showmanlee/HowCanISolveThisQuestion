// 팰린드롬 소떡소떡
// https://www.acmicpc.net/problem/25630

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	int res = 0;
	for (int i = 0; i < n / 2; i++) {
		if (s[i] != s[n - 1 - i]) {
			res++;
		}
	}
	cout << res << '\n';
}

// 주어진 문자열에서 문자를 바꿔 팰린드롬으로 만드는 교체 횟수 구하기