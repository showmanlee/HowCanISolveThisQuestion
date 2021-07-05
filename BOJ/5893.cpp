// 17배
// https://www.acmicpc.net/problem/5893

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	string t = s + "0000";
	string res;
	int jmp = 0;
	while (!s.empty()) {
		int a = s.back() - '0';
		int b = t.back() - '0';
		s.pop_back();
		t.pop_back();
		int p = a + b + jmp;
		jmp = (p >= 2 ? 1 : 0);
		p %= 2;
		res = char(p + '0') + res;
	}
	while (!t.empty()) {
		int a = t.back() - '0';
		t.pop_back();
		int p = a + jmp;
		jmp = (p >= 2 ? 1 : 0);
		p %= 2;
		res = char(p + '0') + res;
	}
	if (jmp == 1)
		res = '1' + res;
	cout << res << '\n';
}

// 주어진 2진수에 17을 곱한 값을 2진수로 출력하기

// 최대 1000자리까지 주어질 수 있기 때문에 10진수 전환 후 2진수 전환은 불가능함
// 17은 16 + 1이기 때문에 2^4 + 1로 접근할 수 있음
// 즉, 왼쪽으로 4번 시프트한 2진수 + 원래 2인수가 답 - 이것을 문자열 기반으로 구현해야 함
// 원래 2진수 s와 시프트한 2진수 t를 이용해, s가 빌 때까지 s와 t의 맨 마지막 숫자(+ 받아올림 수)를 더한 값 % 2를 결과 문자열에 누적
// s가 모두 비면, t만을 이용해 위의 과정을 반복하고, t까지 비었는데 받아올린 수가 남은 경우 해당 수(1)을 결과 문자열에 누적한 뒤 출력하기