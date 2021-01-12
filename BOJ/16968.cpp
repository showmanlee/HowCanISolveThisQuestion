// 차량 번호판 1
// https://www.acmicpc.net/problem/16968

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	int res = (s[0] == 'd' ? 10 : 26);
	bool prev = s[0] == 'd';
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == 'd' != prev) {
			prev = s[i] == 'd';
			res *= (s[i] == 'd' ? 10 : 26);
		}
		else
			res *= (s[i] == 'd' ? 9 : 25);
	}
	cout << res << '\n';
}

// 숫자와 소문자가 들어가는 번호판에서 같은 문자가 반복해서 들어갈 수 없을 때 나올 수 있는 경우의 수는(4자리까지)?
// 이전에 같은 문자가 나왔다면 그 다음자리에 나오는 경우의 수가 하나 줄어든다
// 하지만 반복해서 떨어지는 것은 아니다(문자가 고유해야 되는 건 아니기에 121도 가능)