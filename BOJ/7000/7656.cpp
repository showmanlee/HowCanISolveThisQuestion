// 만능 오라클
// https://www.acmicpc.net/problem/7656

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	getline(cin, s);
	bool recoded = false;
	vector<string> parse;
	int idx = -1;
	for (char c : s) {
		if (!recoded && isupper(c)) {
			idx++;
			parse.push_back("");
			recoded = true;
			parse[idx] += c;
		} else if (recoded && (c == '.' || c == '?')) {
			parse[idx] += c;
			recoded = false;
		} else if (recoded) {
			parse[idx] += c;
		}
	}
	for (string p : parse) {
		if (p.length() >= 7 && p.substr(0, 7) == "What is" && p[p.length() - 1] == '?') {
			string pp = p.substr(5, p.length() - 6);
			pp = "Forty-two " + pp + ".";
			cout << pp << '\n';
		}
	}
}

// 한 줄로 주어지는 문단에서 질문을 뽑아 Forty-two로 답하기

// 문장은 항상 대문자로 시작해 문장 부호로 끝난다 - 그리고 질문은 항상 What is로 시작해 ?로 끝난다
// 이를 이용해 문자열을 분리한 후, 질문인 부분이 What를 Forty-two로, ?를 .로 대치하여 출력한다
// 분리하는 건 모든 문자들을 순회하면서 조건 보기로