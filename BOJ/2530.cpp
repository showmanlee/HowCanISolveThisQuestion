// 인공지능 시계
// https://www.acmicpc.net/problem/2530

#include <iostream>
using namespace std;

int main(void) {
	int h, m, s, t;
	cin >> h >> m >> s >> t;
	s += t;
	m += s / 60;
	s %= 60;
	h += m / 60;
	m %= 60;
	h %= 24;
	cout << h << ' ' << m << ' ' << s << '\n';
}

// 주어진 시간에 초 더하기