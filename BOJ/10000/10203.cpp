// Count Vowels
// https://www.acmicpc.net/problem/10203

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int res = 0;
		for (char c : s) {
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				res++;
			}
		}
		cout << "The number of vowels in " << s << " is " << res << ".\n";
	}
}

// 소문자 문자열에서 모음의 개수 구하기