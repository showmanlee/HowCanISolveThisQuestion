// 2진수 뒤집기
// https://www.acmicpc.net/problem/11179

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
	while (n) {
		s = to_string(n % 2) + s;
		n /= 2;
	}
	int res = 0, p = 1;
	for (char c : s) {
		res += (c - '0') * p;
		p *= 2;
	}
	cout << res << '\n';
}

// 10진수가 주어질 때, 2진수로 변환한 뒤 뒤집어서 다시 10진수로 변환한 결과 출력하기

// 변환하고 변환하면 됩니다 - 2진수 채울 때는 역순으로 채우고, 다시 바꿀 때는 앞에서부터 카운팅하기