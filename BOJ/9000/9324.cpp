// 진짜 메시지
// https://www.acmicpc.net/problem/9324

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		string s, ss;
		cin >> s;
		vector<int> v(26);
		bool skip = false;
		for (char& c : s) {
			if (skip) {
				skip = false;
				continue;
			}
			ss += c;
			v[c - 'A']++;
			if (v[c - 'A'] == 3) {
				ss += c;
				v[c - 'A'] = 0;
				skip = true;
			}
		}
		cout << (s == ss ? "OK" : "FAKE") << '\n';
	}
}

// 대문자 문자열에서 한 문자가 3번째 등장하면 같은 문자를 하나 더 써야 할 때, 주어진 문자열이 규칙에 맞는 문자열인지 판정하기

// 글자를 세주다가 3개가 쌓이면 그 뒤에 같은 글자가 바로 등장해야 함
// 이를 이용해 각 글자를 세면서 별도의 문자열에 채워주고, 같은 글자가 3개가 쌓이면 그 글자를 또 채우고 다음 글자는 건너뛴다
// 그 방식으로 문자열을 만들어 서로 같은지 확인하기