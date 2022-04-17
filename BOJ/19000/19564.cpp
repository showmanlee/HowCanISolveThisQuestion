// 반복
// https://www.acmicpc.net/problem/19564

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int res = 1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i - 1] >= s[i]) {
			res++;
		}
	}
	cout << res << '\n';
}

// abcdefghijklmnopqrstuvwxyz만 입력할 수 있는 상황에서 주어진 문자열을 입력하기 위해 눌러야 하는 키 수는?

// 알파벳이 연속으로 오름차순으로 주어진다면 반복해서 키를 누를 필요가 없음
// 맞붙은 두 문자에서 왼쪽 문자가 오른쪽 문자보다 나중에 오는(또는 같은) 문자였다면 키를 눌러주고, 아니면 계속 진행