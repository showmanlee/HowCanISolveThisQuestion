// JAVA Bitecode
// https://www.acmicpc.net/problem/21867

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s, res;
	cin >> s;
	for (char c : s)
		if (c != 'J' && c != 'A' && c != 'V')
			res += c;
	if (res == "")
		cout << "nojava\n";
	else
		cout << res << '\n';
}

// 대문자로 이루어진 문자열에서 'J', 'A', 'V' 빼고 출력하기(빈 문자열이라면 nojava 출력)

// 문자열을 받고, 각 문자를 순회하며 뺀 문자열을 만들기