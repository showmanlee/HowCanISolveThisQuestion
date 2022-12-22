// 3개만!
// https://www.acmicpc.net/problem/17288

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int res = 0;
	int cnt = 1;
	char prev = s[0];
	for (int i = 1; i < s.length(); i++) {
		if (s[i] - prev == 1) {
			cnt++;
		} else {
			cnt = 1;
		}
		if (cnt == 3) {
			res++;
		} else if (cnt == 4) {
			res--;
		}
		prev = s[i];
	}
	cout << res << '\n';
}

// 주어진 숫자 문자열에서 길이가 정확히 3인 연속된 오름차순 숫자 배열이 몇 번 등장하는지 계산하기

// 오름차순 길이 측정 중 정확히 3인 경우 ++, 넘어가면 --