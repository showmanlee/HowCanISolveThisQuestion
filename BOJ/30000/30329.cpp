// Kick
// https://www.acmicpc.net/problem/30329

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    if (s.length() < 4) {
        cout << 0 << '\n';
    } else {
        string ss = s.substr(0, 3);
        int res = 0;
        for (int i = 3; i < s.length(); i++) {
            ss += s[i];
            if (ss == "kick") {
                res++;
            }
            ss = ss.substr(1);
        }
        cout << res << '\n';
    }
}

// 주어진 소문자 문자열에 kick이 겹친 거 포함해서 몇 번 나오는지 출력하기

// 하나씩 돌려봅니다