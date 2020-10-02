// 이진수 연산
// https://www.acmicpc.net/problem/12813

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string a, b, andd, orr, xorr, nota, notb;
	cin >> a >> b;
	for (int i = 0; i < 100000; i++) {
		andd += (a[i] == '1' && b[i] == '1') ? '1' : '0';
		orr += (a[i] == '1' || b[i] == '1') ? '1' : '0';
		xorr += ((a[i] == '1' && b[i] != '1') || (a[i] != '1' && b[i] == '1')) ? '1' : '0';
		nota += (a[i] == '1') ? '0' : '1';
		notb += (b[i] == '1') ? '0' : '1';
	}
	cout << andd << '\n' << orr << '\n' << xorr << '\n' << nota << '\n' << notb << endl;
}

// 십만대장경