// Telemarketer or not?
// https://www.acmicpc.net/problem/16017

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	bool res = (a == 8 || a == 9) && (d == 8 || d == 9) && b == c;
	cout << (res ? "ignore\n" : "answer\n");
}

// 첫자리와 끝자리가 8이나 9고, 가운데 두 자리가 동일한 번호가 스팸 번호일 때, 스팸 번호 판정하기

// 나온 대로 판정해주면 된다...