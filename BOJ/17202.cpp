// 핸드폰 번호 궁합
// https://www.acmicpc.net/problem/17202

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	string s;
	for (int i = 0; i < 8; i++) {
		s += a[i];
		s += b[i];
	}
	while (s.length() > 2) {
		string tmp;
		for (int i = 0; i < s.length() - 1; i++) {
			int p = ((s[i] - '0') + (s[i + 1] - '0')) % 10;
			tmp += char(p + '0');
		}
		s = tmp;
	}
	cout << s << '\n';
}

// 핸드폰 번호 8자리 2개를 교차로 이어붙인 후 맞닿은 자리의 합 % 10을 아래에 이어 적어나가면서 2자리로 만들 때 그 값은?
// string을 char로 쪼개고, 이걸 int로 바꿔서 계산하고 다시 char로 만들어서 string에 붙인다
// 이걸 2자리가 될 때까지 반복