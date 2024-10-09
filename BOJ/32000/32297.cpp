// 문자열을 만들어요
// https://www.acmicpc.net/problem/32297

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;
    string p = s.substr(0, 4);
    bool res = false;
    for (int i = 0; i <= n - 4; i++) {
        if (p == "gori") {
            res = true;
            break;
        }
        if (i != n - 4) {
            p = p.substr(1) + s[i + 4];
        }
    }
    cout << (res ? "YES" : "NO") << '\n';
}

// 주어진 소문자 문자열 안에 "gori"가 있는지 확인하기