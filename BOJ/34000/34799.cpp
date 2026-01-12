// Strawberry
// https://www.acmicpc.net/problem/34799

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	long long n;
	cin >> n;
	long long res = 0;
	for (char c : s) {
		res += (n - 1) / 26;
		int p = (c - 'a' + 9);
		if (p >= 26) {
			p -= 26;
		}
		if (p <= (n - 1) % 26) {
			res++;
		}
	}
	cout << res << '\n';
}

// 주어진 소문자 문자열에서 같은 문자열을 한 글자씩 뒤로 가게 해서 n번 반복할 때 나오는 r의 개수 구하기