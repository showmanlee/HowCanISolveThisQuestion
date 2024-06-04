// 시간복잡도를 배운 도도
// https://www.acmicpc.net/problem/24510

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int r = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == 'f' && j + 2 < s.length()) {
                if (s.substr(j, 3) == "for") {
                    r++;
                    j += 2;
                }
            } else if (s[j] == 'w' && j + 4 < s.length()) {
                if (s.substr(j, 5) == "while") {
                    r++;
                    j += 4;
                }
            }
        }
        res = max(res, r);
    }
    cout << res << '\n';
}

// 주어진 문자열들 중 "for", "while"이 가장 많이 등장하는 수 구하기