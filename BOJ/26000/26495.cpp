// Big Number
// https://www.acmicpc.net/problem/26495

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		int p = s[i] - '0';
		if (p == 0) {
			cout << "0000\n0  0\n0  0\n0  0\n0000\n";
		} else if (p == 1) {
			cout << "   1\n   1\n   1\n   1\n   1\n";
		} else if (p == 2) {
			cout << "2222\n   2\n2222\n2\n2222\n";
		} else if (p == 3) {
			cout << "3333\n   3\n3333\n   3\n3333\n";
		} else if (p == 4) {
			cout << "4  4\n4  4\n4444\n   4\n   4\n";
		} else if (p == 5) {
			cout << "5555\n5\n5555\n   5\n5555\n";
		} else if (p == 6) { 
			cout << "6666\n6\n6666\n6  6\n6666\n";
		} else if (p == 7) {
			cout << "7777\n   7\n   7\n   7\n   7\n";
		} else if (p == 8) {
			cout << "8888\n8  8\n8888\n8  8\n8888\n";
		} else if (p == 9) {
			cout << "9999\n9  9\n9999\n   9\n   9\n";
		}

		if (i < s.length() - 1) {
			cout << '\n';
		}
	}
}

// 주어진 수를 픽셀이 숫자인 4*5 크기의 숫자로 출력하기

// 그대로 출력하기 - 숫자 사이에 공백 한칸 필요!