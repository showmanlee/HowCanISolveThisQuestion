// 9진수
// https://www.acmicpc.net/problem/14491

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string res;
	while (n != 0) {
		res = char(n % 9 + '0') + res;
		n /= 9;
	}
	cout << res << '\n';
}

// 10진수를 9진수로 변환하기

// 하면 됩니다