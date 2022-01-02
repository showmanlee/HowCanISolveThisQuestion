// 카이사르 암호
// https://www.acmicpc.net/problem/5598

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	for (char& c : s) {
		c -= 3;
		if (c < 'A')
			c += 26;
	}
	cout << s << '\n';
}

// 원래 문장에서 세 개 뒤의 알파벳으로 변환한 카이사르 암호 해독하기
// char에서 세 개 앞으로 빼는데, 만약 알파벳 범위를 벗어나면 26을 더해 범위 안으로 옮긴다