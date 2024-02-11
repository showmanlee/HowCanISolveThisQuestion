// Is Y a Vowel?
// https://www.acmicpc.net/problem/31306

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int a = 0, b = 0;
    for (char c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            a++;
        } else if (c == 'y') {
            b++;
        }
    }
    cout << a << ' ' << (a + b) << '\n';
}

// 주어진 소문자 문자열에서 y를 포함하지 않은 모음 개수와 포함한 개수 구하기

// 세주시길 간곡히 부탁드립니다...