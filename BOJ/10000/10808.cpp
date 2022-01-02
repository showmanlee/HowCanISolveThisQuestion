// 알파벳 개수
// https://www.acmicpc.net/problem/10808

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	int a[26] = { 0, };
	cin >> s;
	for (char c : s)
		a[c - 'a']++;
	for (int i = 0; i < 26; i++)
		cout << a[i] << ' ';
	cout << '\n';
}

// 문자열의 알파벳 개수 구하기
// 아스키 코드