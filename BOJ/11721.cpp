// 열 개씩 끊어 출력하기
// https://www.acmicpc.net/problem/11721

#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        cout << s[i];
        if (i % 10 == 9)
            cout << '\n';
    }
    cout << '\n';
}

// 문자 10개씩 출력하기
// 10개씩 출력하려면 i % 10이 0이 아니라 9임에 주의