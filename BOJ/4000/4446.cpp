// ROT13
// https://www.acmicpc.net/problem/4446

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

bool isVowel(char c) {
	if (isupper(c)) {
		c = tolower(c);
	}
	if (c == 'a' || c == 'i' || c == 'y' || c == 'e' || c == 'o' || c == 'u') {
		return true;
	}
 	return false;
}

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	string vowel = "aiyeou";
	string conso = "bkxznhdcwgpvjqtsrlmf";
	string s;
	while (getline(cin, s)) {
		string res;
		for (char c : s) {
			bool upper = false;
			if (!isalpha(c)) {
				res += c;
				continue;
			} else if (isupper(c)) {
				upper = true;
				c = tolower(c);
			}
			if (isVowel(c)) {
				for (int i = 0; i < 6; i++) {
					if (c == vowel[i]) {
						c = vowel[(i + 3) % 6];
						break;
					}
				}
			} else {
				for (int i = 0; i < 20; i++) {
					if (c == conso[i]) {
						c = conso[(i + 10) % 20];
						break;
					}
				}
			}
			if (upper) {
				c = toupper(c);
			}
			res += c;
		}
		cout << res << '\n';
	}
}

// 자음/모음을 주어진 순서대로 3/10번째 글자로 바꿔야 할 때, 주어진 문자열 변환하기

// 문자열은 대소문자 제한 없고, 알파벳이 아닌 글자도 있으며, 공백도 있고, 여러 줄임 - getline
// 이렇게 한 줄씩 받아서 대소문자면 변환해서 출력하기 - 편하게 하기 위해 대문자일 경우 소문자로 바꾼 뒤 변환하기
// 변환 방식은 자음/모음 순서대로 문자열을 만들어두고, 주어진 글자에서 인덱스를 찾아 바꾸는 것