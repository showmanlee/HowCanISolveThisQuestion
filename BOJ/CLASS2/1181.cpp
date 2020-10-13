// 단어 정렬
// https://www.acmicpc.net/problem/1181

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	if (a.length() != b.length())
		return a.length() < b.length();
	else
		return a < b;
}

int main(void) {
	int n;
	cin >> n;
	vector<string> s;
	for (int i = 0; i < n; i++) {
		string p;
		cin >> p;
		if (find(s.begin(), s.end(), p) == s.end())
			s.push_back(p);
	}
	sort(s.begin(), s.end(), compare);
	for (int i = 0; i < s.size(); i++)
		cout << s[i] << '\n';
}

// 커스텀 소팅 함수 - 오름차순은 < 기준으로
// 중복값은 제거 필요, 20000개이므로 endl로 개행하면 타임아웃 가능성 있음