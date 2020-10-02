// 16진수
// https://www.acmicpc.net/problem/1550

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int translate(char c) {
	if (c >= '0' && c <= '9')
		return c - '0';
	else
		return c - 'A' + 10;
}

int main(void) {
	string sixteen;
	int n = 0;
	cin >> sixteen;
	for (int i = 0; i < sixteen.length(); i++) 
		n += translate(sixteen[sixteen.length() - i - 1]) * (int)pow(16, i);
	cout << n << endl;
}