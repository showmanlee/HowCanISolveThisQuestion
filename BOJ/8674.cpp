// Tabliczka
// https://www.acmicpc.net/problem/8674

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long a, b;
	cin >> a >> b;
	if (a % 2 == 0 || b % 2 == 0) {
		cout << 0 << '\n';
	}
	else {
		cout << (min(a, b)) << '\n';
	}
}

// n*m 초콜릿 조각을 수직/수평으로 한 번 잘라 최대한 똑같이 자를 때 나올 수 있는 조각 차는?

// 두 변 중 하나 이상이 짝수라면 완전히 똑같이 자를 수 있음
// 그렇지 않다면 짧은 쪽을 기준으로 자르면 됨 - 차이는 언제나 짧은 쪽의 길이