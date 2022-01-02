// 문자가 몇갤까
// https://www.acmicpc.net/problem/7600

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		string s;
		getline(cin, s);
		if (s == "#")
			break;
		vector<bool> visit(26);
		for (char c : s) {
			if (isupper(c))
				visit[c - 'A'] = true;
			else if (islower(c))
				visit[c - 'a'] = true;
		}
		int res = 0;
		for (int i = 0; i < 26; i++)
			if (visit[i])
				res++;
		cout << res << '\n';
	}
}

// 대소문자 구별 없이 등장한 알파벳의 수 세기

// getline으로 문자열을 받은 후, 각 문자에 대해 소문자거나 대문자이면 해당되는 알파벳이 등장했다고 표시
// 이후 표시된 알파벳의 수를 세고 출력하기