// 커맨드
// https://www.acmicpc.net/problem/17838

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		string s;
		cin >> s;
		bool res = false;
		if (s.length() == 7) {
			if (s[0] == s[1] && s[1] == s[4] && s[2] == s[3] && s[3] == s[5] && s[5] == s[6] && s[1] != s[2]) {
				res = true;
			}
		}
		cout << res << '\n';
	}
}

// 주어진 커맨드가 AABBABB 꼴을 나타내는지 판별하기

// 정확히 7글자이고, 정확히 2종류의 문자가 포함되며, AABBABB 꼴을 나타내는 문자열
// 7자이고 해당되는 문자들이 모두 같은지 판별한다 - 다만 모든 글자가 같은 경우도 있으니 다른 문자는 반드시 달라야 함