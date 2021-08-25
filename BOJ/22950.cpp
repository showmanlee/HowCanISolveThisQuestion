// 이진수 나눗셈
// https://www.acmicpc.net/problem/22950

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	string s;
	cin >> n >> s >> k;
	bool res = true;
	for (int i = n - k; i < n; i++) {
		if (i < 0)
			continue;
		if (s[i] == '1')
			res = false;
	}
	cout << (res ? "YES" : "NO") << '\n';
}

// 주어진 자릿수의 이진수가 2^k로 나누어떨어지는가?

// 2^k = 1 뒤에 0이 k개 붙은 이진수
// 따라서 길이 n의 문자열로 주어지는 이진수에서 n - k번 인덱스 이후의 문자에 1이 없으면 나누어떨어진다
// 다만 n보다 k가 클 수 있으므로 초기 n - k가 음수인 경우에는 체크하지 않음 - 주어진 이진수의 값이 0인 경우 나누어떨어지므로 판별 자체는 시도