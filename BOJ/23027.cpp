// 1번부터 문제의 상태가...?
// https://www.acmicpc.net/problem/23027

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	char key = 'D';
	for (char c : s) {
		if (c == 'A')
			key = 'A';
		else if (key != 'A' && c == 'B')
			key = 'B';
		else if (key != 'A' && key != 'B' && c == 'C')
			key = 'C';
	}
	for (char& c : s) {
		if (key == 'A') {
			if (c == 'B' || c == 'C' || c == 'D' || c == 'F')
				c = 'A';
		}
		else if (key == 'B') {
			if (c == 'C' || c == 'D' || c == 'F')
				c = 'B';
		}
		else if (key == 'C') {
			if (c == 'D' || c == 'F')
				c = 'C';
		}
		else
			c = 'A';
	}
	cout << s << '\n';
}

// 주어진 조건에 맞추어 대문자 문자열의 글자 변경하기

// A가 등장하면 BCDF를 A로, 그거 말고 B가 등장하면 CDF를 B로, 그거 말고 C가 등장하면 DF를 C로, 아예 없다면 모든 글자를 A로 바꿔라
// 입력받은 뒤 문자열을 한 번 훑으며 글자 등장 여부를 찾고, 다시 한 번 돌면서 글자를 바꾼다