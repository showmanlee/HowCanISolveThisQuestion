// 8진수
// https://www.acmicpc.net/problem/2998

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	string res;
	int cnt = 0, p = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		p += (s[i] - '0') * pow(2, cnt);
		cnt++;
		if (cnt == 3) {
			res = (char)(p + '0') + res;
			cnt = 0;
			p = 0;
		}
	}
	if (cnt != 0)
		res = (char)(p + '0') + res;
	cout << res << '\n';
}

// 2진수를 8진수로 변환하기

// 뒤에서부터 숫자를 가져와 자릿수에 더하면서 숫자 3개가 될 때마다 해당 자릿수를 결과 앞에 붙이고 개수와 자릿수 초기화하기
// 탐색을 마친 후 남은 자릿수가 있다면 앞에 붙이기