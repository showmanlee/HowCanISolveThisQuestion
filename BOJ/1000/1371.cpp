// 가장 많은 글자
// https://www.acmicpc.net/problem/1371

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> count(26);
	string s;
	while (cin >> s) {
		for (char c : s)
			count[c - 'a']++;
	}
	int max = 0;
	string res;
	for (int i = 0; i < 26; i++) {
		if (count[i] > max) {
			max = count[i];
			res = ('a' + i);
		}
		else if (count[i] == max) {
			res += ('a' + i);
		}
	}
	cout << res << '\n';
}

// 여러 줄의 소문자 문장에서 가장 많이 나온 글자(들)은?
// 그저 세보면 됩니다 - 다만 가장 많이 나온 글자가 여러 개 나올 수 있으니 그거 감안하면서 출력하고
// 또 명확한 입력 종료점이 주어지지 않으니 while을 통한 입력이 필요함