// 수학숙제
// https://www.acmicpc.net/problem/2870

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

string translate(string s) {
	while (s[0] == '0' && s.length() > 1) {
		s = s.substr(1);
	}
	return s;
}

bool compare(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a.length() < b.length();
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> res;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		string t;
		for (char c : s) {
			if (isdigit(c)) {
				t += c;
			}
			else {
				if (t != "") {
					t = translate(t);
					res.push_back(t);
				}
				t = "";
			}
		}
		if (t != "") {
			t = translate(t);
			res.push_back(t);
		}
	}
	sort(res.begin(), res.end(), compare);
	for (string s : res) {
		cout << s << '\n';
	}
}

// 주어진 문자열들 사이에 낀 정수들만 뽑아 정렬한 결과 출력하기

// 한 문자열에서 숫자만 등장한 경우 카운팅해서 정렬 배열에 넣기 - 0이 앞에 있는 경우 모두 없애야 함(0 제외)
// 다만 일반적인 문자열 정렬은 사전순으로 배치되기에(22 -> 235 -> 33), 정수형으로 정렬될 수 있도록 손을 써둬야 함