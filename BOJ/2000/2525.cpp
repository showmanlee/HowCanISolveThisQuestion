// 오븐 시계
// https://www.acmicpc.net/problem/2525

#include <iostream>
using namespace std;

int main(void) {
	int h, m, t;
	cin >> h >> m >> t;
	m += t;
	h += m / 60;
	m %= 60;
	h %= 24;
	cout << h << ' ' << m << '\n';
}

// 인공지능 시계의 초침 없는 버전