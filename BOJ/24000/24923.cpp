// Canadians, eh?
// https://www.acmicpc.net/problem/24923

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	getline(cin, s);
	bool res = s.substr(s.length() - 3, 3) == "eh?";
	cout << (res ? "Canadian!" : "Imposter!") << '\n';
}

// 주어진 문자열이 eh?로 끝나는지 구하기