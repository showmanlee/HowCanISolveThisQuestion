// 진법 변환
// https://www.acmicpc.net/problem/2745

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	int a;
	cin >> s >> a;
	int res = 0, p = 1;
	for (int i = s.length() - 1; i >= 0; i--) {
		int d = 0;
		if (s[i] >= '0' && s[i] <= '9')
			d = s[i] - '0';
		else
			d = s[i] - 'A' + 10;
		res += d * p;
		p *= a;
	}
	cout << res << '\n';
}

// a진법 수를 10진법으로 변환하기
// a진법을 문자열로 받고, 역순으로 돌면서 대응되는 숫자 * 현재까지의 자릿수 곱을 결과값에 넣어준다
// 진법 개념의 기본 문제

// BOJ 800문제 돌파!
// 1000문제 안에 플4 가자