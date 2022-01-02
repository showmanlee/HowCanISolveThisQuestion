// 다이얼
// https://www.acmicpc.net/problem/5622

#include <iostream>
#include <string>
using namespace std;

int dial(char c) {
	if (c == 'A' || c == 'B' || c == 'C')
		return 3;
	if (c == 'D' || c == 'E' || c == 'F')
		return 4;
	if (c == 'G' || c == 'H' || c == 'I')
		return 5;
	if (c == 'J' || c == 'K' || c == 'L')
		return 6;
	if (c == 'M' || c == 'N' || c == 'O')
		return 7;
	if (c == 'P' || c == 'Q' || c == 'R' || c == 'S')
		return 8;
	if (c == 'T' || c == 'U' || c == 'V')
		return 9;
	if (c == 'W' || c == 'X' || c == 'Y' || c == 'Z')
		return 10;
	return 0;
}

int main(void) {
	string s;
	cin >> s;
	int res = 0;
	for (char c : s)
		res += dial(c);
	cout << res << '\n';
}

// 단순 대입 후 합산