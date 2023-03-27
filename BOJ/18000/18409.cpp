// 母音を数える (Counting Vowels)
// https://www.acmicpc.net/problem/18409

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string s;
	cin >> n >> s;
	int res = 0;
	for (char c : s) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			res++;
		}
	}
	cout << res << '\n';
}

// 주어진 소문자 문자열에 있는 모음 개수 세기

// 세세요