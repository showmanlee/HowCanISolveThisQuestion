// 머신 코드
// https://www.acmicpc.net/problem/2929

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int cnt = 0;
	int res = 0;
	for (char c : s) {
		if (c >= 'a' && c <= 'z') {
			cnt++;
		} else {
			if (cnt % 4 != 0) {
				res += 4 - (cnt % 4);
			}
			cnt = 1;
		}
	}
	cout << res << '\n';
}

// 대문자로 표현되는 명령과 소문자로 표현되는 파라미터들로 구성된 명령어 쌍에서 명령이 4바이트 단위로 있어야 할 때, 채워야 하는 공백 문자의 수는?

// 사이사이 들어가는 소문자의 수 + 1이 4로 나누어떨어지지 않을 때, 남는 칸 만큼 채워준다