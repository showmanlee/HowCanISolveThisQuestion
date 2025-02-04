// Problem C
// https://www.acmicpc.net/problem/33106

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int t = 0; t < n; t++) {
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'c') {
                if (i == s.length() - 1) {
                    s[i] = 'k';
                } else if (s[i + 1] == 'h') {
                    s[i] = '*';
                } else if (s[i + 1] == 'e' || s[i + 1] == 'i' || s[i + 1] == 'y') {
                    s[i] = 's';
                } else {
                    s[i] = 'k';
                }
            }
        }
        string res;
        bool pass = false;
        for (char c : s) {
            if (pass) {
                pass = false;
                continue;
            }
            if (c == '*') {
                res += 'c';
                pass = true;
                continue;
            }
            res += c;
        }
        cout << res << '\n';
    }
}

// 주어진 조건대로 소문자 문자열의 c를 발음으로 치환하기