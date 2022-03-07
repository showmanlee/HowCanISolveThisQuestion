// 좋은놈 나쁜놈
// https://www.acmicpc.net/problem/4447

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	getline(cin, s);
	int n = stoi(s);
	for (int t = 0; t < n; t++) {
		getline(cin, s);
		int g = 0, b = 0;
		for (char c : s) {
			if (c == 'G' || c == 'g') {
				g++;
			}
			else if (c == 'B' || c == 'b') {
				b++;
			}
		}
		cout << s << " is ";
		if (g < b) {
			cout << "A BADDY";
		}
		else if (g > b) {
			cout << "GOOD";
		}
		else {
			cout << "NEUTRAL";
		}
		cout << '\n';
	}
}

// 주어진 이름에서 g와 b의 수를 세고 대소관계 출력하기

// g가 더 많으면 GOOD, b가 더 많으면 A BADDY(BAD가 아님에 주의), 같으면 NEUTRAL
// 문자열에 공백이 들어가므로 getline으로 받기 - 나머지는 직접 세주면 됨