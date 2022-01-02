// 피카츄
// https://www.acmicpc.net/problem/14405

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int idx = 0;
	while (true) {
		if (idx < s.length() - 1 && s.substr(idx, 2) == "pi")
			idx += 2;
		else if (idx < s.length() - 1 && s.substr(idx, 2) == "ka")
			idx += 2;
		else if (idx < s.length() - 2 && s.substr(idx, 3) == "chu")
			idx += 3;
		else
			break;
	}
	cout << (idx == s.length() ? "YES" : "NO") << '\n';
}

// pi, ka, chu만 말할 수 있는 피카츄가 주어진 소문자 문자열을 모두 말할 수 있는가?

// 문자열을 입력받은 후, 0번 인덱스부터 탐색 시작
// 만약 현재 인덱스부터 두 글자가 pi, ka거나, 세 글자가 chu인 경우 인덱스를 늘리고, 그렇지 않으면 탈출
// 그렇게 해서 인덱스가 문자열 길이를 가리킨다면 성공, 그렇지 않으면 실패