// Логины 
// https://www.acmicpc.net/problem/29108

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
typedef pair<char, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    bool res = true;
    for (int i = 0; i < s.length(); i++) {
        if ((i == 0 || i == 1) && !islower(s[i])) {
            res = false;
        }
        if (i >= 2 && !isdigit(s[i])) {
            res = false;
        }
    }
    if (s.length() <= 2) {
        res = false;
    }
    cout << (res ? "Correct" : "Incorrect") << '\n';
}

// 주어진 소문자+숫자 문자열이 첫 두 글자는 소문자 2개, 그 뒤는 숫자 형태를 만족하는지 확인하기