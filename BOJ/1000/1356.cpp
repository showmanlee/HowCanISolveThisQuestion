// 유진수
// https://www.acmicpc.net/problem/1356

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	bool res = false;
	for (int i = 1; i < s.length(); i++) {
		long long a = 1, b = 1;
		for (int j = 0; j < s.length(); j++) {
			if (j < i)
				a *= s[j] - '0';
			else
				b *= s[j] - '0';
		}
		if (a == b)
			res = true;
	}
	cout << (res ? "YES" : "NO") << '\n';
}

// 어떤 수를 두 부분으로 나눴을 때 각 부분의 숫자의 곱이 같은 경우가 발생하는가?

// 우선 수를 문자열로 받는다 - 그리고 어떤 인덱스를 기준으로 해당 인덱스까지/부터 존재하는 숫자의 곱을 구해 같으면 결과값에 체크 표시
// 브루트포스의 성격도 가지고 있음