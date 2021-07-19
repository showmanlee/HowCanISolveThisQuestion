// 홀수일까 짝수일까
// https://www.acmicpc.net/problem/5988

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
		if ((s[s.length() - 1] - '0') % 2 == 0)
			cout << "even\n";
		else
			cout << "odd\n";
	}
}

// 주어진 수가 홀수인지 짝수인지 판별하기

// 입력되는 수의 범위가 10^60이므로 정수형으로는 받을 수 없음
// 하지만 홀짝 구분법은 맨 마지막 숫자만 보면 됨 - 따라서 문자열로 받고 마지막 수가 홀수인지 짝수인지만 보면 됨