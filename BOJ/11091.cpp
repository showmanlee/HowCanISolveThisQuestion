// 알파벳 전부 쓰기
// https://www.acmicpc.net/problem/11091

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		vector<bool> shown(26);
		for (char& c : s) {
			if (isupper(c))
				c = tolower(c);
			if (islower(c))
				shown[c - 'a'] = true;
		}
		bool fail = false;
		for (bool b : shown)
			if (!b)
				fail = true;
		if (fail) {
			cout << "missing ";
			for (int i = 0; i < 26; i++)
				if (!shown[i])
					cout << (char)(i + 'a');
			cout << '\n';
		}
		else
			cout << "pangram\n";
	}
}

// 입력된 문자열이 모든 알파벳이 들어간 팬그램인지 판정하고, 그렇지 않다면 빠진 알파벳 출력하기
// 대문자가 들어오면 소문자로 바꾼 후, 배열 체크하기