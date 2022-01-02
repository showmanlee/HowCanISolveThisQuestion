// 팰린드롬인지 확인하기
// https://www.acmicpc.net/problem/10988

#include <iostream>
#include <string>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int n = s.length();
	bool res = true;
	for (int i = 0; i < n; i++) {
		if (s[i] != s[n - i - 1]) {
			res = false;
			break;
		}
	}
	cout << res << '\n';
}

// 말 그대로 주어진 문자열이 팰린드롬인지 확인하기
// 양옆의 문자가 같은 문자인지 확인하고, 그렇지 않은 곳이 발견되면 아니라고 판정