// 행복한지 슬픈지
// https://www.acmicpc.net/problem/10769

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	getline(cin, s);
	int happy = 0, sad = 0;
	if (s.length() >= 3) {
		for (int i = 0; i <= s.length() - 3; i++) {
			string ss = s.substr(i, 3);
			if (ss == ":-)") {
				happy++;
			} else if (ss == ":-(") {
				sad++;
			}
		}
	}
	if (happy == 0 && sad == 0) {
		cout << "none\n";
	} else if (happy == sad) {
		cout << "unsure\n";
	} else if (happy < sad) {
		cout << "sad\n";
	} else {
		cout << "happy\n";
	}
}

// 문자열 안의 :-) / :-(의 개수에 따라 결과 출력하기

// 문자열에 공백이 있으므로 getline으로 받은 후, 뒤에서부터 3글자씩 보면서 개수 세기