// 일기 암호화하기
// https://www.acmicpc.net/problem/33869

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string k;
	cin >> k;
	vector<int> board(26), visit(26);
	int idx = 0;
	for (char c : k) {
		if (!visit[c - 'A']) {
			board[idx] = c - 'A';
			visit[c - 'A'] = true;
			idx++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (!visit[i]) {
			board[idx] = i;
			visit[i] = true;
			idx++;
		}
	}
	string s;
	cin >> s;
	for (char c : s) {
		char r = board[c - 'A'] + 'A';
		cout << r;
	}
	cout << '\n';
}

// 주어진 키를 이용해 대문자 변환표를 만들고, 다음으로 주어지는 대문자 문자열을 변환하기