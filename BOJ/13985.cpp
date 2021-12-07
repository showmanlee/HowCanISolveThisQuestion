// Equality
// https://www.acmicpc.net/problem/13985

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	char a, _, b, c;
	cin >> a >> _ >> b >> _ >> c;
	cout << (a - '0' + b - '0' == c - '0' ? "YES" : "NO") << '\n';
}

// a + b = c로 주어진 수식이 맞는지 확인하기

// 5개의 문자를 모두 문자로 입력받은 뒤, 1, 3번째 문자의 합이 5번째 문자와 같은지 확인하기