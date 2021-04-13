// 나는 친구가 적다 (Small)
// https://www.acmicpc.net/problem/16171

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s, k, p;
	cin >> s >> k;
	for (char c : s)
		if (!isdigit(c))
			p += c;
	cout << (p.find(k) != string::npos) << '\n';
}

// 알파벳 소문자와 대문자만으로 이뤄진 문자열에 숫자가 섞였는데, 해당 문자열에서 알파벳 소문자와 대문자만으로 이뤄진 다른 문자열을 찾을 수 있는가?

// '원래 문자열'이 알파벳만으로 있는데, 거기에 숫자가 섞였다 - '입력된 문자열'에서 숫자를 빼면 '원래 문자열'이 나온다
// 문자열을 입력받은 후, 거기서 숫자를 뺀 새로운 문자열을 만들고, 거기서 find를 이용해 찾는 문자열이 있는지 확인한다