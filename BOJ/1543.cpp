// 문서 검색
// https://www.acmicpc.net/problem/1543

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s, t;
	getline(cin, s);
	getline(cin, t);
	int res = 0;
	if (s.length() >= t.length()) {
		for (int i = 0; i <= s.length() - t.length(); i++) {
			if (s.substr(i, t.length()) == t) {
				res++;
				i += t.length() - 1;
			}
		}
	}
	cout << res << '\n';
}

// 한 문자열에서 다른 문자열이 중복 없이 얼마나 등장하는가?
// (abababa에서 aba는 3번이 아닌 2번 등장한다고 생각)
// 문자 사이에 공백이 등장할 수 있고, 최대 길이만 다를 뿐 s가 t보다 길다는 보장이 없음에 주의
// 처음부터 substr로 부분 문자열 탐색 후, 같은 부분을 찾았다면 그 다음 인덱스로 점프