// 2033년 밈 투표
// https://www.acmicpc.net/problem/29731

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	vector<string> v = {
		"Never gonna give you up",
		"Never gonna let you down",
		"Never gonna run around and desert you",
		"Never gonna make you cry",
		"Never gonna say goodbye",
		"Never gonna tell a lie and hurt you",
		"Never gonna stop",
	};
	string s;
	getline(cin, s);
	int n = stoi(s);
	bool res = false;
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		bool p = false;
		for (int j = 0; j < 7; j++) {
			if (s == v[j]) {
				p = true;
			}
		}
		if (!p) {
			res = true;
		}
	}
	cout << (res ? "Yes" : "No") << '\n';
}

// 주어진 문자열들이 주어진 노래가사에 모두 포함되어 있는지 판정하기

// 확인해봅시다... - getline으로다가