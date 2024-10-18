// Password check
// https://www.acmicpc.net/problem/15239

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool pass = false;
        if (n >= 12) {
            int n = 0;
            for (char c : s) {
                if (isupper(c)) {
                    n |= 1;
                } else if (islower(c)) {
                    n |= 2;
                } else if (isdigit(c)) {
                    n |= 4;
                } else {
                    n |= 8;
                }
            }
            if (n == 15) {
                pass = true;
            }
        }
        cout << (pass ? "valid" : "invalid") << '\n';
    }
}

// 주어진 비밀번호에서 소문자 대문자 숫자 특수문자가 모두 한 글자 이상 들어가는지 확인하기