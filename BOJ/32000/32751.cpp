// 햄버거
// https://www.acmicpc.net/problem/32751

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;
    bool res = true;
    if (s[0] != 'a' || s[s.length() - 1] != 'a') {
        res = false;
    }
    int aa = 0, bb = 0, cc = 0, dd = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a') {
            aa++;
        }
        if (s[i] == 'b') {
            bb++;
        }
        if (s[i] == 'c') {
            cc++;
        }
        if (s[i] == 'd') {
            dd++;
        }
        if (i != s.length() - 1) {
            if (s[i] == s[i + 1]) {
                res = false;
            }
        }
    }
    if (a < aa || b < bb || c < cc || d < dd) {
        res = false;
    }
    cout << (res ? "Yes" : "No") << '\n';
}

// 주어진 조건대로 햄버거가 만들어졌는지 확인하기