// 문자와 문자열
// https://www.acmicpc.net/problem/27866

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	int n;
	cin >> n;
	cout << s[n - 1] << '\n';
}

// 주어진 문자열의 n번째 문자 출력하기

// s[n - 1]