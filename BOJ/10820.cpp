// 문자열 분석
// https://www.acmicpc.net/problem/10820

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(void) {
	while (true) {
		string s;
		getline(cin, s);
		if (s.length() == 0)
			break;
		int l = 0, u = 0, d = 0, b = 0;
		for (char c : s) {
			if (islower(c))
				l++;
			if (isupper(c))
				u++;
			if (isdigit(c))
				d++;
			if (isblank(c))
				b++;
		}
		cout << l << ' ' << u << ' ' << d << ' ' << b << '\n';
	}
}

// 각 문자열에 있는 소문자/대문자/숫자/공백의 수 구하기
// for로 돌려주면서 cctype에 있는 함수 활용
// 마지막줄이 빈 줄로 주어지면 입력이 종료됨에 주의