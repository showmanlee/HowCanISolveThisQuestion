// 次の文字 (Next Character)
// https://www.acmicpc.net/problem/24084

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n - 1; i++) {
		if (s[i + 1] == 'J') {
			cout << s[i] << '\n';
		}
	}
}

// 각 문자를 순회하며 바로 앞 문자가 J일 때 해당 문자 출력하기