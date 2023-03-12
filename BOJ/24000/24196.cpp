// Gömda ord
// https://www.acmicpc.net/problem/24196

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	string res;
	int idx = 0;
	do {
		res += s[idx];
		idx += s[idx] - 'A' + 1;
	} while (idx < s.length());
	cout << res << '\n';
}

// 대문자 문자열에서 첫 글자부터 시작해 해당 알파벳 순서만큼 다음 글자 출력하기

// idx가 문자열을 벗어날 때까지 계속 밀어서 적어준다