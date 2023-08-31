// 오렌지먹은지오랜지
// https://www.acmicpc.net/problem/27962

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	bool res = false;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j <= i; j++)
		if (s[j] != s[n - i - 1 + j]) {
			cnt++;
		}
		if (cnt == 1) {
			res = true;
			break;
		}
	}
	cout << (res ? "YES" : "NO") << '\n';
}

// 문자열에서 맨 앞/맨 뒤부터 시작한 길이가 같은 부분 문자열을 뽑았을 때 한 글자만 다른 경우가 나오는지 판정하기

// 판정하면 됩니다