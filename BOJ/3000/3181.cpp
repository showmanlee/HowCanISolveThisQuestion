// 줄임말 만들기
// https://www.acmicpc.net/problem/3181

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s, res;
	cin >> s;
	res += toupper(s[0]);
	while (cin >> s) {
		if (s == "i"|| s ==  "pa" || s ==  "te" || s ==  "ni" || s ==  "niti" || s ==  "a" || s ==  "ali" || s ==  "nego" || s ==  "no" || s ==  "ili") {
			continue;
		}
		res += toupper(s[0]);
	}
	cout << res << '\n';
}

// 영어 문자열에서 각 단어의 첫 글자를 따 대문자 줄임말을 만드는데, 주어진 단어 풀은 첫 번째로 등장하지 않는 한 포함하지 않을 때, 줄임말 만들기

// 단어들을 하나씩 받아서 단어 풀에 없을 경우 첫 글자를 대문자화하여 줄임말에 넣는다
// 단 첫 단어는 풀에 있어도 넣어야 하므로 그렇게 넣어준다...