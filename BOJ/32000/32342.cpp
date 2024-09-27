// 와우와 쿼리
// https://www.acmicpc.net/problem/32342

#include <iostream>
#include <vector>
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
        int res = 0;
        if (s.length() >= 3) {
            for (int i = 0; i < s.length() - 2; i++) {
                if (s[i] == 'W' && s[i + 1] == 'O' && s[i + 2] == 'W') {
                    res++;
                }
            }
        }
        cout << res << '\n';
    }
}

// 문자열 내 있는 WOW의 개수 구하기