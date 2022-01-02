// 럭키 스트레이트
// https://www.acmicpc.net/problem/18406

#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i < s.length() / 2)
            a += s[i] - '0';
        else
            b += s[i] - '0';
    }
    cout << (a == b ? "LUCKY" : "READY") << '\n';
}

// 어떤 자연수를 반으로 나눴을 때 각 조각의 자릿수의 합이 같은가?
// 문자열로 받아 직접 세보면 되지요