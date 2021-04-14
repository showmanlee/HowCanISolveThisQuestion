// 유학 금지
// https://www.acmicpc.net/problem/2789

#include <iostream>
#include <string>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s, no = "CAMBRIDGE";
    cin >> s;
    for (char c : s) {
        if (no.find(c) == string::npos)
            cout << c;
    }
    cout << '\n';
}

// 대문자로 구성된 문자열에서 CAMBRIDGE를 구성하는 알파벳을 뺀 결과는?
// CAMBRIDGE에 없는 문자만 출력하면 되지 - find() == string::npos