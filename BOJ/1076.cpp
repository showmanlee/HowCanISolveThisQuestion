// 저항
// https://www.acmicpc.net/problem/1076

#include <iostream>
#include <string>
using namespace std;

long long digit(string s) {
	if (s == "black")
		return 0;
	if (s == "brown")
		return 1;
	if (s == "red")
		return 2;
	if (s == "orange")
		return 3;
	if (s == "yellow")
		return 4;
	if (s == "green")
		return 5;
	if (s == "blue")
		return 6;
	if (s == "violet")
		return 7;
	if (s == "grey")
		return 8;
	if (s == "white")
		return 9;
}

long long power(string s) {
	if (s == "black")
		return 1;
	if (s == "brown")
		return 10;
	if (s == "red")
		return 100;
	if (s == "orange")
		return 1000;
	if (s == "yellow")
		return 10000;
	if (s == "green")
		return 100000;
	if (s == "blue")
		return 1000000;
	if (s == "violet")
		return 10000000;
	if (s == "grey")
		return 100000000;
	if (s == "white")
		return 1000000000;
}

int main(void) {
	string a, b, c;
	cin >> a >> b >> c;
	long long res = (digit(a) * 10 + digit(b)) * power(c);
	cout << res << '\n';
}

// 저항 색깔 보고 저항값 알아내기
// 조건식