// 열 순서
// https://www.acmicpc.net/problem/16495

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	long long p = 1, res = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		res += p * (s[i] - 'A' + 1);
		p *= 26;
	}
	cout << res << '\n';
}

// A부터 시작하는 엑셀 열 번호의 순서 출력하기

// A부터 Z까지 1~26, 이후 27부터는 AA, AB, AC... 형태로 증가
// 따라서 뒤에서부터 자릿수를 더해가며 계산할 수 있음
// 문자열의 길이는 최대 10이므로 최댓값은 26^10 - long long 범위에서 계산하기