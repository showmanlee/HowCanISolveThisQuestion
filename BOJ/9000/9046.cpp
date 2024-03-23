// 복호화
// https://www.acmicpc.net/problem/9046

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        vector<int> v(26);
        string s;
        getline(cin, s);
        int maxx = 0;
        for (char c : s) {
            if (islower(c)) {
                v[c - 'a']++;
                maxx = max(maxx, v[c - 'a']);
            }
        }
        char res = ' ';
        for (int j = 0; j < 26; j++) {
            if (v[j] == maxx) {
                if (res == ' ') {
                    res = 'a' + j;
                } else {
                    res = '?';
                    break;
                }
            }
        }
        cout << res << '\n';
    }
}

// 주어진 소문자 문자열에서 가장 많이 나온 문자 출력하기 - 동률이면 ?

// 세주고 동률 체크하고 출력하기