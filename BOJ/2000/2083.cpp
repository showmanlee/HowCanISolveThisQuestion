// 럭비 클럽
// https://www.acmicpc.net/problem/2083

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (true) {
		string s;
		int a, b;
		cin >> s >> a >> b;
		if (s == "#")
			break;
		cout << s << ' ';
		if (a > 17 || b >= 80)
			cout << "Senior\n";
		else
			cout << "Junior\n";
	}
}

// 주어진 선수의 나이와 몸무게를 보고 청소년부인지 성인부인지 판정하기

// 나이가 17 초과 or 몸무게가 80 이상일 때 성인부
// 조건을 잘 보고 조건식 만들어서 판정하기