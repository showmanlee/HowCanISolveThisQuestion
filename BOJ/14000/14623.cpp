// 감정이입
// https://www.acmicpc.net/problem/14623

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	long long x = 0, y = 0;
	long long key = 1;
	while (a.length() != 0) {
		x += key * (a.back() - '0');
		a.pop_back();
		key *= 2;
	}
	key = 1;
	while (b.length() != 0) {
		y += key * (b.back() - '0');
		b.pop_back();
		key *= 2;
	}
	string res;
	long long p = x * y;
	while (p != 0) {
		res = to_string(p % 2) + res;
		p /= 2;
	}
	cout << res << '\n';
}

// 두 이진수를 곱한 결과를 이진수로 출력하기

// 두 이진수의 길이는 최대 30 - 즉 2^30, int 범위 안에 들어온다는 것
// 이 둘을 곱하면 2^60까지 나올 수 있고, long long 범위 안에 들어가므로 십진수-이진수 변환으로 처리해볼 수 있음