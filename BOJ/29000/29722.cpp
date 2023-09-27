// 브실혜성
// https://www.acmicpc.net/problem/29722

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int y = stoi(s.substr(0, 4));
	int m = stoi(s.substr(5, 2));
	int d = stoi(s.substr(8));
	int n;
	cin >> n;
	d--;
	m--;
	d += n;
	if (d >= 30) {
		m += d / 30;
		d %= 30;
		if (m >= 12) {
			y += m / 12;
			m %= 12;
		}
	}
	d++;
	m++;
	cout.width(4);
	cout.fill('0');
	cout << y << '-';
	cout.width(2);
	cout.fill('0');
	cout << m << '-';
	cout.width(2);
	cout.fill('0');
	cout << d << '\n';
}

// 한 달이 30일인 달력에서 주어진 날의 n일 후 구하기

// 이렇게 되면 나머지로 구할 수 있음