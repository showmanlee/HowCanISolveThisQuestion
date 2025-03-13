// UOS 문자열
// https://www.acmicpc.net/problem/32929

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	char res = 'U';
	if (n % 3 == 2) {
		res = 'O';
	} else if (n % 3 == 0) {
		res = 'S';
	}
	cout << res << '\n';
}

// UOS가 반복되는 문자열에서 n번째 문자 구하기