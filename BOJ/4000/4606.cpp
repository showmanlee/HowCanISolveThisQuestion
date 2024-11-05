// The Seven Percent Solution
// https://www.acmicpc.net/problem/4606

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    while (true) {
        string s;
        getline(cin, s);
        if (s == "#") {
            break;
        }
        string ret;
        for (char c : s) {
            if (c == ' ') {
                ret += "%20";
            } else if (c == '!') {
                ret += "%21";
            } else if (c == '$') {
                ret += "%24";
            } else if (c == '%') {
                ret += "%25";
            } else if (c == '(') {
                ret += "%28";
            } else if (c == ')') {
                ret += "%29";
            } else if (c == '*') {
                ret += "%2a";
            } else {
                ret += c;
            }
        }
        cout << ret << '\n';
    }
}

// 주어진 문자열의 일부 특수문자를 바꿔서 출력하기