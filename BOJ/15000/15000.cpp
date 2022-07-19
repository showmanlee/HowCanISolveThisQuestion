// CAPS
// https://www.acmicpc.net/problem/15000

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    for (char c : s) {
        c = c - 'a' + 'A';
        cout << c;
    }
    cout << '\n';
}

// 주어진 소문자 문자열을 대문자로 변환하기

// 합시다 - 딱 소문자만 주어집니다