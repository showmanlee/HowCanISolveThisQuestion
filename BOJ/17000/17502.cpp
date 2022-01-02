// 클레어와 팰린드롬
// https://www.acmicpc.net/problem/17502

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n / 2 + 1; i++) {
		if (s[i] == '?' && s[n - i - 1] == '?')
			s[i] = s[n - i - 1] = 'a';
		else if (s[i] == '?')
			s[i] = s[n - i - 1];
		else if (s[n - i - 1] == '?')
			s[n - i - 1] = s[i];
	}
	cout << s << '\n';
}

// 팰린드롬의 일부 글자가 빠져있을 때, 빈칸을 채워 팰린드롬 완성하기
// 대칭되는 두 글자가 모두 빠진 경우 임시용으로 'a'를 채우고, 한 글자만 빠진 경우 대응되는 자리의 글자를 넣는다