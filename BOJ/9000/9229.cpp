// 단어 사다리
// https://www.acmicpc.net/problem/9229

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while(true) {
		string s;
		cin >> s;
		if (s == "#") {
			break;
		}
		vector<string> v;
		v.push_back(s);
		while (cin >> s) {
			if (s == "#") {
				break;
			}
			v.push_back(s);
		}
		bool res = true;
		string prev = "";
		for (string st : v) {
			if (prev == "") {
				prev = st;
				continue;
			} else if (prev.length() != st.length()) {
				res = false;
				break;
			}
			int cnt = 0;
			for (int i = 0; i < st.length(); i++) {
				if (prev[i] != st[i]) {
					cnt++;
				}
			}
			if (cnt != 1) {
				res = false;
				break;
			}
			prev = st;
		}
		cout << (res ? "Correct" : "Incorrect") << '\n';
	}
}
 
// 대문자 문자열 배열이 주어질 때, 맞붙은 문자열의 길이가 서로 같고 다른 글자가 정확히 한 글자인지 확인하기

// 두 문자열이 같고 다른 글자가 하나 뿐인지 확인해보면 됩니다
// 그리고 입력 종료 타이밍만 잘 잡으면 됩니다 - # 연속 2번