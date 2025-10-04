// 알파벳 점수 계산기
// https://www.acmicpc.net/problem/34553

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int res = 1;
	int cur = 1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i - 1] < s[i]) {
			cur++;
		} else {
			cur = 1;
		}
		res += cur;
	}
	cout << res << '\n';
}

// 문자열들을 순회하여 연속해서 내림차순이 발생할 때 1점씩 늘려 계산할 때, 최종 점수 출력하기