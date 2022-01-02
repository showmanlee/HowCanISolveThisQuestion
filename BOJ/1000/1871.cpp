// 좋은 자동차 번호판
// https://www.acmicpc.net/problem/1871

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int sa = 0, sb = stoi(s.substr(4));
		string pa = s.substr(0, 3);
		for (int j = 0; j < 3; j++)
			sa += (pa[j] - 'A') * pow(26, 2 - j);
		if (abs(sa - sb) <= 100)
			cout << "nice\n";
		else
			cout << "not nice\n";
	}
}

// AAA-0000 꼴의 번호판에서 앞 세 자리 알파벳을 26진수로 보고 수치화한 값과 뒤 네 자리의 차가 100 이하일 때 좋은 번호판이라고 한다. 주어진 번호판이 좋은 번호판인가?
// AAA 부분만 잘 변환해주면 ok - 뒤는 stoi가 해결해줄 거야