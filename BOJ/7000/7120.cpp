// String
// https://www.acmicpc.net/problem/7120

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    char prev = ' ';
    string res;
    for (char c : s) {
        if (prev != c) {
            prev = c;
            res += c;
        }
    }
    cout << res << '\n';
}

// 문자열에서 중복된 글자 제거해고 출력하기