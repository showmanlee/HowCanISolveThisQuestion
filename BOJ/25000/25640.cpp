// MBTI
// https://www.acmicpc.net/problem/25640

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		if (s == t) {
			res++;
		}
	}
	cout << res << '\n';
}

// 내 MBTI와 친구들의 MBTI가 주어졌을 때, 내와 MBTI가 같은 사람의 수 구하기

// 같은 거 세보세요