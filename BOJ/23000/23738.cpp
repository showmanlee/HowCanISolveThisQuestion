// Ресторан
// https://www.acmicpc.net/problem/23738

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    string res;
    for (char c : s) {
        if (c == 'B') {
            res += 'v';
        } else if (c == 'E') {
            res += "ye";
        } else if (c == 'H') {
            res += 'n';
        } else if (c == 'P') {
            res += 'r';
        } else if (c == 'C') {
            res += 's';
        } else if (c == 'Y') {
            res += 'u';
        } else if (c == 'X') {
            res += 'h';
        } else {
            res += tolower(c);
        }
    }
    cout << res << '\n';
}

// 주어진 러시아어의 영어로 읽는 방법 출력하기