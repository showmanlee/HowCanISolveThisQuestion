// 상수
// https://www.acmicpc.net/problem/2908

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string a, b;
	cin >> a >> b;
	char swap;
	swap = a[0];
	a[0] = a[2];
	a[2] = swap;
	swap = b[0];
	b[0] = b[2];
	b[2] = swap;
	if (a > b)
		cout << a << endl;
	else
		cout << b << endl;
}