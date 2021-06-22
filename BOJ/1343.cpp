// 폴리오미노
// https://www.acmicpc.net/problem/1343

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	string res;
	int idx = 0;
	while (idx < s.length()) {
		if (s[idx] == '.') {
			res += '.';
			idx++;
		}
		else {
			if (idx + 4 <= s.length() && s[idx] == 'X' && s[idx + 1] == 'X' && s[idx + 2] == 'X' && s[idx + 3] == 'X') {
				res += "AAAA";
				idx += 4;
			}
			else if (idx + 2 <= s.length() && s[idx] == 'X' && s[idx + 1] == 'X') {
				res += "BB";
				idx += 2;
			}
			else {
				res = "-1";
				break;
			}
		}
	}
	cout << res << '\n';
}

// AAAA와 BB로 X와 .으로 구성된 문자열을 모두 채울 수 있다면 사전상에서 가장 먼저 나오는 결과를 출력하고, 그럴 수 없다면 -1 출력하기

// 사전상으로 우선되는 경우의 수는 A가 최대한 먼저 나오는 것
// 따라서 각 문자를 따라가다가 X를 만나면 A -> B 순서로 채워준다
// 발견한 X에서 4칸이 X라면 A를 채우고, 2칸이 X라면 B를 채운다 - A를 우선으로
// 만약 두 경우가 모두 아니라면 채울 수 없는 상황이므로 결과 문자열을 -1로 만들고 탐색 종료