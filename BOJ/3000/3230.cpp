// 11 月 (November)
// https://www.acmicpc.net/problem/3230

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	cout << (a + b * 7 <= 30) << '\n';
}

// 2022년 11월 a일의 b주일 뒤 날짜가 2022년 11월 안인지 확인하기

// a + (b * 7) <= 30