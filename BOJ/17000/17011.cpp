// Cold Compress
// https://www.acmicpc.net/problem/17011

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        string s;
        cin >> s;
        char prev = ' ';
        int cnt = 0;
        for (char c : s) {
            if (prev == ' ' || prev == c) {
                cnt++;
            } else {
                cout << cnt << ' ' << prev << ' ';
                cnt = 1;
            }
            prev = c;
        }
        cout << cnt << ' ' << prev << ' ';
        cout << '\n';
    }
}

// 주어진 공백없는 문자열을 연속된 문자 개수 - 문자 형태로 압축하기