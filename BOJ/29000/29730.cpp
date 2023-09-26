// 임스의 데일리 인증 스터디
// https://www.acmicpc.net/problem/29730

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string& a, string& b) {
	if (a.length() >= 7 && a.substr(0, 7) == "boj.kr/" && b.length() >= 7 && b.substr(0, 7) == "boj.kr/") {
		int aa = stoi(a.substr(7));
		int bb = stoi(b.substr(7));
		return aa < bb;
	} else if (a.length() >= 7 && a.substr(0, 7) == "boj.kr/") {
		return false;
	} else if (b.length() >= 7 && b.substr(0, 7) == "boj.kr/") {
		return true;
	}
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	return a < b;
}

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	string s;
	getline(cin, s);
	int n = stoi(s);
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		getline(cin, v[i]);
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++) {
		cout << v[i] << '\n';
	}
}

// 주어진 문자열들을 boj.kr/... 꼴의 문자열을 뒤로, 그 외의 문자열을 앞으로 두고 boj.kr/...은 뒤에 붙는 수의 오름차순으로, 그 외의 문자열은 길이 -> 사전 순으로 오름차순으로 정렬하기

// 커스텀 정렬